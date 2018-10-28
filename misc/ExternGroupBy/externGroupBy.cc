/*************************************************************************
  > File Name:       externGroupBy.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    The actual implementation of externGroupBy
 ************************************************************************/

#include "externGroupBy.h"
#include "utility.h"

namespace ExternGroupBy
{
/**
 * The baseline for External GroupBy. The implementation is exactly the same as brute_force.py.
 */
void
externGroupByBaseline()
{
    int memoryLimit;
    std::cin >> memoryLimit;
    std::map<std::string, std::vector<std::string>> key_dict;
    for (std::string line; std::getline(std::cin, line);)
    {
        std::stringstream ss(line);
        std::string buf;
        std::vector<std::string> tokens;
        while (ss >> buf)
        {
            tokens.emplace_back(buf);
        }
        if (!tokens.empty())
        {
            auto key = tokens[0];
            auto val = tokens[1];
            if (key_dict.find(key) == key_dict.end())
            {
                key_dict[key] = {val};
            }
            else
            {
                key_dict[key].emplace_back(val);
            }
        }
    }
    for (auto &item : key_dict)
    {
        std::sort(item.second.begin(), item.second.end());
        std::cout << item.first << " " << Utility::join(item.second, " ") << std::endl;
    }
}

struct Comparator
{
    bool
    operator()(std::pair<std::string, std::string> item1, std::pair<std::string, std::string> item2)
    {
        return item1.first > item2.first;
    }
};

/**
 * Save the buffer to the file. The function will sort the entries in the buffer, increment the runNum, and
 * clear the buffer.
 * @param buffer a vector of key-value entries that is to be saved
 */
static void
saveBuffer(std::vector<std::pair<std::string, std::string>> &buffer)
{
    // used to determine the filename
    static int runNum = 0;
    typedef std::function<bool(std::pair<std::string, std::string>, std::pair<std::string, std::string>)> Comparator;
    Comparator comp = [](std::pair<std::string, std::string> item1, std::pair<std::string, std::string> item2) -> bool
    {
        return item1.first > item2.first;
    };
    std::ofstream outfile;
    std::sort(buffer.begin(), buffer.end(), comp);
    outfile.open("run" + std::to_string(runNum));
    for (auto &item : buffer)
    {
        outfile << item.first << " " << item.second << std::endl;
    }
    outfile.close();
    buffer.clear();
    runNum++;
}

/**
 * Our actual implementation
 */
void
externGroupBy()
{
    unsigned long memoryLimit;
    std::cin >> memoryLimit;

    unsigned long L = memoryLimit / 2;

    typedef std::function<bool(std::pair<std::string, std::string>, std::pair<std::string, std::string>)> Comparator;
    Comparator comp = [](std::pair<std::string, std::string> item1, std::pair<std::string, std::string> item2) -> bool
    {
        return item1.first > item2.first;
    };
    // define a min heap
    std::priority_queue<std::pair<std::string, std::string>,
                        std::vector<std::pair<std::string, std::string>>,
                        Comparator> pq(comp);
    std::vector<std::pair<std::string, std::string>> buffer;
    unsigned long accumulateSize = 0;

    for (std::string line; std::getline(std::cin, line);)
    {
        std::stringstream ss(line);
        std::string buf;
        std::vector<std::string> tokens;
        while (ss >> buf)
        {
            tokens.emplace_back(buf);
        }
        if (!tokens.empty())
        {
            auto key = tokens[0];
            auto val = tokens[1];
            unsigned long keyValSize = key.length() + val.length();
            if (accumulateSize + keyValSize > L)
            {
                accumulateSize -= buffer.size();
                saveBuffer(buffer);
            }
            buffer.emplace_back(std::pair<std::string, std::string>{key, val});
            accumulateSize += keyValSize;
        }
    }
}
}