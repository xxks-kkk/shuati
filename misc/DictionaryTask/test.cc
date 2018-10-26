/*************************************************************************
  > File Name:       test.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/26/18
  > Description:
    
    Unit test for the dictionary API.
 ************************************************************************/

#include "dictionary.h"
#include <cassert>

int main()
{
    auto dict = new Dictionary();
    dict->insert("hello", "world");
    assert(dict->getDefinition("hello") == "world");
    std::vector<std::string> exp = {"hello"};
    assert(dict->retrieve("h") == exp);
    return 0;
}