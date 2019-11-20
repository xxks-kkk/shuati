project(shuati/leetcode)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_DIR}/hackerrank)

# For batch test purpose (see testall.sh)
file(WRITE target_list.txt
  "IPAddressValidation\n")
configure_file(target_list.txt target_list.txt COPYONLY)

configure_file(IPAddressValidation/input001.txt input001.txt COPYONLY)
configure_file(IPAddressValidation/output001_exp.txt output001_exp.txt COPYONLY)
add_executable(IPAddressValidation
  IPAddressValidation/ipAddressValidation.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(IPAddressValidation PRIVATE ${INCLUDE_DIR}/cppinclude)
