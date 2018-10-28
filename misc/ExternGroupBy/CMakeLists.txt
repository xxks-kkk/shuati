#
#  > File Name:       CMakeLists.txt
#  > Author:          Zeyuan Hu
#  > Mail:            iamzeyuanhu@utexas.edu
#  > Created Time:    10/19/18
#  > Description:
#
#    Compile the external GroupBy project

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/misc/ExternGroupBy)

configure_file(config.txt config.txt)
configure_file(scripts/brute_force.py scripts/brute_force.py)
configure_file(scripts/gen_test_data.py scripts/gen_test_data.py)

add_executable(unitTests
        unitTests.cc
        externGroupBy.cc
        utility.cc)