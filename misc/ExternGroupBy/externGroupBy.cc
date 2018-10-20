/*************************************************************************
  > File Name:       externGroupBy.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    The actual implementation of externGroupBy
 ************************************************************************/

#include "externGroupBy.h"

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
        std::cout << item.first << " " << ExternGroupBy::join(item.second, " ") << std::endl;
    }
}

/**
 * A helper method to join the std::vector<std::string> with delimiter and output one single string
 * @param vec a vector<string>
 * @param delim the delimiter
 * @return the joined string
 */
static std::string
join(const std::vector<std::string> &vec, const char *delim)
{
    std::stringstream res;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(res, delim));
    unsigned long size = res.str().size();
    return res.str().substr(0, size-1);
}
}