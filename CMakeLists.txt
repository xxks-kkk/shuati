cmake_minimum_required(VERSION 3.9)
project(shuati)

set(CMAKE_CXX_STANDARD 11)
include_directories(leetcode)
# FIXME: Remove this line as we may get clash with our c headers. Gradually fix all the #include "queue.h" to
# #include "cppinclude/queue.h" and then remove this line.
include_directories(leetcode/cppinclude)

add_executable(2
        leetcode/2-AddTwoNumbers/addTwoNumbers.cc
        leetcode/cppinclude/linkedList.cc)

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

add_executable(20
        leetcode/20-ValidParentheses/validParentheses.cc)

add_executable(21
        leetcode/21-MergeTwoSortedList/mergeTwoSortedList.c
        leetcode/cinclude/linkedlist.c)

add_executable(23
        leetcode/23-MergekSortedLists/mergekSortedLists.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(25
        leetcode/25-ReverseNodesink-Group/reverseNodesink-Group.cc
        leetcode/cppinclude/linkedList.cc
        leetcode/cppinclude/linkedList.h)

add_executable(27
        leetcode/27-RemoveElement/removeElement.cc)

add_executable(30
        leetcode/30-SubstringwithConcatenationofAllWords/substringwithConcatenationofAllWords.cc)

add_executable(32
        leetcode/32-LongestValidParentheses/longestValidParentheses.cc)

add_executable(35
        leetcode/35-SearchInsertPosition/searchInsertPosition.cc)

add_executable(42
        leetcode/42-TrappingRainWater/trappingRainWater.cc)

add_executable(53
        leetcode/53-MaximumSubarray/maximumSubarray.cc)

add_executable(54
        leetcode/54-SpiralMatrix/spiralMatrix.cc)

add_executable(62
        leetcode/62-UniquePaths/uniquePaths.cc)

add_executable(70
        leetcode/70-ClimbingStairs/climbingStairs.cc)
        
add_executable(88
        leetcode/88-MergeSortedArray/mergeSortedArray.cc)
        
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

add_executable(122
        leetcode/122-BestTimetoBuyandSellStockII/bestTimetoBuyandSellStockII.cc)

add_executable(124
        leetcode/124-BinaryTreeMaximumPathSum/binaryTreeMaximumPathSum.cc
        leetcode/cppinclude/bt.cc)

add_executable(141
        leetcode/141-LinkedListCycle/linkedListCycle.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(145
        leetcode/145-BinaryTreePostorderTraversal/binaryTreePostorderTraversal.cc
        leetcode/cppinclude/bt.cc)

add_executable(146
        leetcode/146-LRUCache/lRUCache.cc)

add_executable(155
        leetcode/155-MinStack/minStack.cc)

add_executable(159
        leetcode/159-LongestSubstringWithAtMostTwoDistinctCharacters/longestSubstringWithAtMostTwoDistinctCharacters.cc)

add_executable(160
        leetcode/160-IntersectionofTwoLinkedLists/intersectionofTwoLinkedLists.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(165
        leetcode/165-CompareVersionNumbers/compareVersionNumbers.c)

add_executable(186
        leetcode/186-ReverseWordsInAStringII/reverseWordsInAStringII.cc)

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

add_executable(242
        leetcode/242-ValidAnagram/validAnagram.cc)

add_executable(250
        leetcode/250-CountUnivalueSubtrees/countUnivalueSubtrees.cc
        leetcode/cppinclude/bt.cc)

add_executable(253
        leetcode/253-MeetingRoomsII/meetingRoomsII.cc)

add_executable(255
        leetcode/255-VerifyPreorderSequenceinBinarySearchTree/verifyPreorderSequenceinBinarySearchTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(257
        leetcode/257-BinaryTreePaths/binaryTreePaths.cc
        leetcode/cppinclude/bt.cc)

add_executable(261
        leetcode/261-GraphValidTree/graphValidTree.cc)
        
add_executable(268
        leetcode/268-MissingNumber/missingNumber.cc)

add_executable(270
        leetcode/270-ClosestBinarySearchTreeValue/closestBinarySearchTreeValue.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(272
        leetcode/272-ClosestBinarySearchTreeValueII/closestBinarySearchTreeValueII.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/bst.cc)

add_executable(278
        leetcode/278-FirstBadVersion/firstBadVersion.cc)

add_executable(283
        leetcode/283-MoveZeroes/moveZeroes.cc)

add_executable(289
        leetcode/289-GameOfLife/gameOfLife.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(297
        leetcode/297-SerializeandDeserializeBinaryTree/serializeandDeserializeBinaryTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(298
        leetcode/298-BinaryTreeLongestConsecutiveSequence/binaryTreeLongestConsecutiveSequence.cc
        leetcode/cppinclude/bt.cc)

add_executable(301
        leetcode/301-RemoveInvalidParentheses/removeInvalidParentheses.cc)

add_executable(322
        leetcode/322-CoinChange/coinChange.cc)

add_executable(333
        leetcode/333-LargestBSTSubtree/largestBSTSubtree.cc
        leetcode/cppinclude/bt.cc)

add_executable(337
        leetcode/337-HouseRobberIII/houseRobberIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(344
        leetcode/344-ReverseString/reverseString.cc)

add_executable(346
        leetcode/346-MovingAveragefromDataStream/movingAveragefromDataStream.cc)

add_executable(347
        leetcode/347-TopKFrequentElements/topKFrequentElements.cc)

add_executable(349
        leetcode/349-IntersectionOfTwoArrays/intersectionOfTwoArrays.cc)

add_executable(350
        leetcode/350-IntersectionofTwoArraysII/intersectionofTwoArraysII.cc)

add_executable(366
        leetcode/366-FindLeavesofBinaryTree/findLeavesofBinaryTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(369
        leetcode/369-PlusOneLinkedList/plusOneLinkedList.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(387
        leetcode/387-FirstUniqueCharacterinaString/firstUniqueCharacterinaString.cc)

add_executable(412
        leetcode/412-FizzBuzz/fizzBuzz.c)
        
add_executable(414
        leetcode/414-ThirdMaximumNumber/thirdMaximumNumber.cc)

add_executable(437
        leetcode/437-PathSumIII/pathSumIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(443
        leetcode/443-StringCompression/stringCompression.cc)

add_executable(460
        leetcode/460-LFUCache/lFUCache.cc)

add_executable(582
        leetcode/582-KillProcess/killProcess.cc)

add_executable(609
        leetcode/609-FindDuplicateFileinSystem/findDuplicateFileinSystem.cc)

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

add_executable(739
        leetcode/739-DailyTemperatures/dailyTemperatures.cc)

add_executable(796
        leetcode/796-RotateString/rotateString.cc)

add_executable(811
        leetcode/811-SubdomainVisitCount/subdomainVisitCount.cc)

add_executable(829
        leetcode/829-ConsecutiveNumbersSum/consecutiveNumbersSum.cc)

add_executable(842
        leetcode/842-SplitArrayintoFibonacciSequence/splitArrayintoFibonacciSequence.cc)

add_executable(000
        leetcode/cppinclude/queue.h
        leetcode/cppinclude/queue.tpp
        misc/QueueArrayImplementation/queueArrayImplementation.cc)

add_executable(001
        misc/GetFruits/getFruits.cc)

add_executable(002
        misc/HDRT/simplePrint.c)

add_executable(003
        misc/ReformattingDates/reformattingDates.cc)

add_executable(004
        misc/MaximizingProfitFromStocks/maximizingProfitFromStocks.cc)

add_executable(005
        misc/IsThisATree/isThisATree.cc)

add_executable(006
        misc/FindTheWinner/findTheWinner.cc)

add_executable(007
        misc/SmartSale/smartSale.cc)

add_executable(008
        misc/WebsitePagination/websitePagination.cc)

add_executable(009
        misc/RemovingChocolates/removingChocolates.cc)

add_executable(010
        misc/ConsecutiveSum/consecutiveSum.cc)

add_executable(011
        misc/ThePerfectTeam/thePerfectTeam.cc)

add_executable(012
        misc/WorkSchedule/workSchedule.cc)

add_executable(013
        misc/MergeString/mergeString.cc)

add_executable(014
        misc/BudgetShopping/budgetShopping.cc)

add_executable(015
        misc/DistinctPairs/distinctPairs.cc)