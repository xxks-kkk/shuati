/*************************************************************************
  > File Name:       utility.h
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/20/18
  > Description:
    
    Helper functions for the project
 ************************************************************************/

#ifndef SHUATI_UTILITY_H
#define SHUATI_UTILITY_H

#include <string>
#include <vector>
#include <sstream>
#include <array>
#include <memory>
#include <cstdio>
#include <iostream>
#include <stdexcept>

namespace Utility
{
std::string
join(const std::vector <std::string> &vec, const char *delim);

std::string
exec(const char *cmd);
}

#endif //SHUATI_UTILITY_H