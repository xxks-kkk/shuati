/*************************************************************************
  > File Name:       benchmark.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    The benchmark for the externGroupBy program
 ************************************************************************/

#include "externGroupBy.h"

using ptr2ExternGroupBy = void (*)();

class UnitTests
{

};

void
benchmark(ptr2ExternGroupBy pfcn)
{
    (*pfcn)();
}

int
main()
{
    //TODO: A tempory workaround for CLion. Remove to submit
    // https://youtrack.jetbrains.com/issue/CPP-3153
    // https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files
    std::freopen("input-small.txt", "r", stdin);
    std::freopen("test-output-small.txt", "w", stdout);

    ptr2ExternGroupBy pfcn = &ExternGroupBy::externGroupByBaseline;
    benchmark(pfcn);

    std::fclose(stdin);
    std::fclose(stdout);
}