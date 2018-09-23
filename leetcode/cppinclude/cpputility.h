#include "shared_headers.h"

#ifndef SHUATI_UTILITY_H
#define SHUATI_UTILITY_H

// cpp: we can add our own message during the compilation
//#pragma message "We use utiltiy.h from cppinclude"
//#warning "We use correct utility.h"

namespace CPPUtility
{

// split the string by the given delimiter
std::vector <std::string>
split(const std::string &str, const std::string &delim);

// convert the vector<string> to vector<int>
std::vector<int>
convertToInt(const std::vector<std::string>& input);
}

#endif