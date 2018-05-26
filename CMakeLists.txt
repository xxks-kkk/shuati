cmake_minimum_required(VERSION 3.9)
project(shuati)

set(CMAKE_CXX_STANDARD 11)
include_directories(leetcode/cppinclude)

add_executable(99
        leetcode/99-RecoverBinarySearchTree/recoverBinarySearchTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(101
        leetcode/101-SymmetricTree/symmetricTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(107
        leetcode/107-BinaryTreeLevelOrderTraversalII/binaryTreeLevelOrderTraversalII.cc
        leetcode/cppinclude/bt.cc)

add_executable(110
        leetcode/110-BalancedBinaryTree/balancedBinaryTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(124
        leetcode/124-BinaryTreeMaximumPathSum/binaryTreeMaximumPathSum.cc
        leetcode/cppinclude/bt.cc)

add_executable(145
        leetcode/145-BinaryTreePostorderTraversal/binaryTreePostorderTraversal.cc
        leetcode/cppinclude/bt.cc)

add_executable(234
        leetcode/234-PalindromeLinkedList/palindromeLinkedList.cc)

add_executable(235
        leetcode/235-LowestCommonAncestorofaBinarySearchTree/lowestCommonAncestorofaBinarySearchTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(236
        leetcode/236-LowestCommonAncestorOfABinaryTree/lowestCommonAncestorOfABinaryTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(250
        leetcode/250-CountUnivalueSubtrees/countUnivalueSubtrees.cc
        leetcode/cppinclude/bt.cc)

add_executable(298
        leetcode/298-BinaryTreeLongestConsecutiveSequence/binaryTreeLongestConsecutiveSequence.cc
        leetcode/cppinclude/bt.cc)

add_executable(337
        leetcode/337-HouseRobberIII/houseRobberIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(366
        leetcode/366-FindLeavesofBinaryTree/findLeavesofBinaryTree.cc
        leetcode/cppinclude/bt.cc)