/*************************************************************************
  > File Name:       externGroupBy.h
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    Fill in the purpose of this source file here.
 ************************************************************************/

#ifndef SHUATI_EXTERNGROUPBY_H
#define SHUATI_EXTERNGROUPBY_H

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>

using ptr2ExternGroupBy = void (*)();

namespace ExternGroupBy
{
void
externGroupByBaseline();

}

#endif //SHUATI_EXTERNGROUPBY_H