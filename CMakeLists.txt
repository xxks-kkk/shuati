cmake_minimum_required(VERSION 3.9)
project(shuati)

set(CMAKE_CXX_STANDARD 11)
include_directories(cppinclude)

add_executable(234 leetcode/234-PalindromeLinkedList/palindromeLinkedList.cc)

add_executable(110
        leetcode/110-BalancedBinaryTree/balancedBinaryTree.cc
        cppinclude/bt.cc)

add_executable(101
        leetcode/101-SymmetricTree/symmetricTree.cc
        cppinclude/bt.h)