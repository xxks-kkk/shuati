cmake_minimum_required(VERSION 3.9)
project(shuati)

# This project requires C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Always use libc++ on Clang
include(CheckCXXSourceRuns)
 macro(CHECK_CXX_COMPILER_AND_LINKER_FLAGS _RESULT _CXX_FLAGS _LINKER_FLAGS) 
   set(CMAKE_REQUIRED_FLAGS ${_CXX_FLAGS}) 
   set(CMAKE_REQUIRED_LIBRARIES ${_LINKER_FLAGS}) 
   set(CMAKE_REQUIRED_QUIET TRUE) 
   CHECK_CXX_SOURCE_RUNS("int main(int argc, char **argv) { return 0; }" ${_RESULT}) 
   set(CMAKE_REQUIRED_FLAGS "") 
   set(CMAKE_REQUIRED_LIBRARIES "") 
endmacro() 

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang") 
   CHECK_CXX_COMPILER_AND_LINKER_FLAGS(HAS_LIBCPP "-stdlib=libc++" "-stdlib=libc++") 
   if (HAS_LIBCPP) 
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++") 
     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++") 
     set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++") 
     CHECK_CXX_COMPILER_AND_LINKER_FLAGS(HAS_LIBCPPABI "-stdlib=libc++" "-stdlib=libc++ -lc++abi") 
     if(HAS_LIBCPPABI) 
       set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi") 
       set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lc++abi") 
       message(STATUS "shuati: using libc++ and libc++abi.") 
     else() 
       message(STATUS "shuati: using libc++.") 
     endif() 
   else() 
     message(STATUS "shuati: NOT using libc++.") 
   endif() 
endif()

# Specify the build directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cmake-build-debug)
set(CMAKE_BUILD_DIR ${PROJECT_SOURCE_DIR}/cmake-build-debug)

# Specify the root of the include directory
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(leetcode)
add_subdirectory(misc)
