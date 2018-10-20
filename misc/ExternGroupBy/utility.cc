/*************************************************************************
  > File Name:       utility.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/20/18
  > Description:
    
    Helper functions for the project
 ************************************************************************/

#include "utility.h"

namespace Utility
{
/**
 * A helper method to join the std::vector<std::string> with delimiter and output one single string
 * @param vec a vector<string>
 * @param delim the delimiter
 * @return the joined string
 */
std::string
join(const std::vector <std::string> &vec, const char *delim)
{
    std::stringstream res;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(res, delim));
    std::string ret = res.str();
    ret.pop_back();
    return ret;
}

/**
 * Execute the given cmd in shell
 * @param cmd the cmd to be executed
 * @return stdout of the execution output
 */
std::string
exec(const char *cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get()))
    {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
}