/*************************************************************************
  > File Name:       unitTests.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    Unit tests for the external GroupBy implementation.
 ************************************************************************/

#include "externGroupBy.h"
#include "utility.h"

#include <cassert>

const std::string WORK_DIR = "/Users/zeyuan/Documents/projects/shuati/misc/ExternGroupBy/";
const std::string CONFIG_PATH = WORK_DIR + "config.txt";
const std::string BRUTE_FORCE_PATH = WORK_DIR + "scripts/brute_force.py";
const std::string GENERATE_PATH = WORK_DIR + "scripts/gen_test_data.py";


/**
 * This class reads the config.txt and construct the data structures
 * to be consumed by the UnitTests framework
 */
class ConfigFile
{
    friend class UnitTests;

public:
    explicit ConfigFile(std::string filepath,
                        std::string brute_force_path,
                        std::string generate_path)
    {
        _config_path = std::move(filepath);
        _brute_force_path = std::move(brute_force_path);
        _generate_path = std::move(generate_path);

        std::ifstream input(_config_path);
        std::string line;
        std::vector<std::vector<int>> tokens;
        while (getline(input, line))
        {
            if (!line.empty() && line[0] != '#')
            {
                std::vector<int> tmp;
                std::stringstream ss(line);
                std::string buf;
                while (ss >> buf)
                {
                    tmp.emplace_back(std::stoi(buf));
                }
                if (!tmp.empty())
                {
                    tokens.emplace_back(tmp);
                }
            }
        }
        _tokens = tokens;
    }

private:
    std::string _config_path;
    std::string _brute_force_path;
    std::string _generate_path;
    std::vector<std::vector<int>> _tokens;
};

/**
 * The unit test framework for the External GroupBy implementation
 */
class UnitTests
{
public:
    explicit UnitTests(ConfigFile config) : _config(std::move(config))
    {
        _input_path = WORK_DIR + "input.txt";
        _output_path = WORK_DIR + "output.txt";
        _test_output_path = WORK_DIR + "test-output.txt";
    }

    void
    test(ptr2ExternGroupBy pfcn)
    {
        auto tokens = _config._tokens;
        int numbering = 0;
        std::cout << tokens.size() << " test cases" << std::endl;
        for (auto &item: tokens)
        {
            std::cout << "Testing: config file row " << numbering << " ";
//            create_input(item);
            generate_ans();
            generate_res(pfcn);
            check();
            numbering++;
            std::cout << "pass" << std::endl;
        }
    }

    ~UnitTests() {
        std::string cmd = "rm " + _output_path;
        Utility::exec(cmd.c_str());
        cmd = "rm " + _test_output_path;
        Utility::exec(cmd.c_str());
        cmd = "rm " + _input_path;
        Utility::exec(cmd.c_str());
    }
private:
    /**
     * Invoke the gen_test_data.py to create the input.txt
     * @param item vector<int>, which represents one row of the config.txt
     */
    void
    create_input(std::vector<int> &item)
    {
        std::stringstream cmd;
        cmd << _config._generate_path << " ";
        for (auto &token: item)
        {
            cmd << token << " ";
        }
        cmd << "> " << _input_path;
        Utility::exec(cmd.str().c_str());
    }

    /**
     * We invoke brute_force.py to generate the expected answer
     */
    void
    generate_ans()
    {
        std::stringstream cmd;
        cmd << _config._brute_force_path << " " << "< " << _input_path <<
            " > " << _output_path;
        Utility::exec(cmd.str().c_str());
    }

    /**
     * We invoke our External GroupBy implementation
     * @param pfcn the function pointer to the implementation
     */
    void
    generate_res(ptr2ExternGroupBy pfcn)
    {
        std::ifstream in(_input_path);
        std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
        std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

        std::ofstream out(_test_output_path);
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

        (*pfcn)();

        std::cin.rdbuf(cinbuf);   //reset to standard input again
        std::cout.rdbuf(coutbuf); //reset to standard output again
    }

    /**
     * We check the correctness of our implementation
     */
    void
    check()
    {
        // TODO: We need to consider the memory usage constraint as well in the check. We need to gather this information
        // from somewhere.
        std::stringstream cmd;
        cmd << "diff " << _output_path << " " << _test_output_path;
        auto result = Utility::exec(cmd.str().c_str());
        assert(result.empty());
    }

    ConfigFile _config;
    std::string _input_path;
    std::string _output_path;
    std::string _test_output_path;
};

int
main()
{
    ConfigFile config = ConfigFile(CONFIG_PATH,
                                   BRUTE_FORCE_PATH,
                                   GENERATE_PATH);
    UnitTests unitTests = UnitTests(config);
//    ptr2ExternGroupBy pfcn = &ExternGroupBy::externGroupByBaseline;
//    unitTests.test(pfcn);

    ptr2ExternGroupBy pfcn = &ExternGroupBy::externGroupBy;
    unitTests.test(pfcn);
}