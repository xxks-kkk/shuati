#include "cpputility.h"

namespace CPPUtility
{
  std::vector<std::string>
  split(const std::string &str, const std::string &delim)
  {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
  }

  std::vector<int>
  convertToInt(const std::vector<std::string>& input)
  {
    std::vector<int> res;
    for(auto& i : input)
    {
        res.push_back(std::stoi(i));
    }
    return res;
  }
}
