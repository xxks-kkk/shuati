cmake_minimum_required(VERSION 3.9)
project(shuati)

set(CMAKE_CXX_STANDARD 11)
include_directories(leetcode/cppinclude)

add_executable(4
        leetcode/4-MedianofTwoSortedArrays/medianofTwoSortedArrays.cc)

add_executable(9
        leetcode/9-PalindromeNumber/palindromeNumber.cc)

add_executable(10
        leetcode/10-RegularExpressionMatching/regularExpressionMatching.cc)

add_executable(14
        leetcode/14-LongestCommonPrefix/longestCommonPrefix.cc
        leetcode/cppinclude/trie.h
        leetcode/cppinclude/trie.cc)

add_executable(23
        leetcode/23-MergekSortedLists/mergekSortedLists.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(53
        leetcode/53-MaximumSubarray/maximumSubarray.cc)

add_executable(98
        leetcode/98-ValidateBinarySearchTree/validateBinarySearchTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(99
        leetcode/99-RecoverBinarySearchTree/recoverBinarySearchTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(101
        leetcode/101-SymmetricTree/symmetricTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(107
        leetcode/107-BinaryTreeLevelOrderTraversalII/binaryTreeLevelOrderTraversalII.cc
        leetcode/cppinclude/bt.cc)

add_executable(108
        leetcode/108-ConvertSortedArraytoBinarySearchTree/convertSortedArraytoBinarySearchTree.cc
        leetcode/cppinclude/bst.cc
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

add_executable(155
        leetcode/155-MinStack/minStack.cc)

add_executable(207
        leetcode/207-CourseSchedule/courseSchedule.cc
        leetcode/cppinclude/graph.h
        leetcode/cppinclude/graph.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(208
        leetcode/208-ImplementTrie/implementTrie.cc)

add_executable(213
        leetcode/213-HouseRobberII/houseRobberII.cc)

add_executable(222
        leetcode/222-CountCompleteTreeNodes/countCompleteTreeNodes.cc
        leetcode/cppinclude/bt.cc)

add_executable(230
        leetcode/230-KthSmallestElementinaBST/kthSmallestElementinaBST.cc
        leetcode/cppinclude/bt.cc)

add_executable(232
        leetcode/232-ImplementQueueusingStacks/implementQueueusingStacks.cc)

add_executable(234
        leetcode/234-PalindromeLinkedList/palindromeLinkedList.cc
        leetcode/cppinclude/linkedList.cc)

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

add_executable(255
        leetcode/255-VerifyPreorderSequenceinBinarySearchTree/verifyPreorderSequenceinBinarySearchTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(257
        leetcode/257-BinaryTreePaths/binaryTreePaths.cc
        leetcode/cppinclude/bt.cc)

add_executable(270
        leetcode/270-ClosestBinarySearchTreeValue/closestBinarySearchTreeValue.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(272
        leetcode/272-ClosestBinarySearchTreeValueII/closestBinarySearchTreeValueII.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(297
        leetcode/297-SerializeandDeserializeBinaryTree/serializeandDeserializeBinaryTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(298
        leetcode/298-BinaryTreeLongestConsecutiveSequence/binaryTreeLongestConsecutiveSequence.cc
        leetcode/cppinclude/bt.cc)

add_executable(333
        leetcode/333-LargestBSTSubtree/largestBSTSubtree.cc
        leetcode/cppinclude/bt.cc)

add_executable(337
        leetcode/337-HouseRobberIII/houseRobberIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(366
        leetcode/366-FindLeavesofBinaryTree/findLeavesofBinaryTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(369
        leetcode/369-PlusOneLinkedList/plusOneLinkedList.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(437
        leetcode/437-PathSumIII/pathSumIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(658
        leetcode/658-FindKClosestElements/findKClosestElements.cpp)

add_executable(663
        leetcode/663-EqualTreePartition/equalTreePartition.cc
        leetcode/cppinclude/bt.cc)

add_executable(669
        leetcode/669-TrimaBinarySearchTree/trimaBinarySearchTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(704
        leetcode/704-BinarySearch/binarySearch.cc)

add_executable(842
        leetcode/842-SplitArrayintoFibonacciSequence/splitArrayintoFibonacciSequence.cc)
