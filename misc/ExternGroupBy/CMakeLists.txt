#
#  > File Name:       CMakeLists.txt
#  > Author:          Zeyuan Hu
#  > Mail:            iamzeyuanhu@utexas.edu
#  > Created Time:    10/19/18
#  > Description:
#
#    Compile the external GroupBy project

add_executable(benchmark
        benchmark.cc
        externGroupBy.cc
        utility.cc
        )

add_executable(unitTests
        unitTests.cc
        externGroupBy.cc
        utility.cc)