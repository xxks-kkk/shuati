/*************************************************************************
  > File Name:       benchmark.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    The benchmark for the externGroupBy program
 ************************************************************************/

#include "externGroupBy.h"

/**
 * Benchmark the external GroupBy implementation
 * @param pfcn the function pointer to a specific external GroupBy implementation
 */
void
benchmark(ptr2ExternGroupBy pfcn)
{
    (*pfcn)();
}

int
main()
{

}