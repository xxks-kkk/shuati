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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/cmake-build-debug)

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

add_executable(22
        leetcode/22-GenerateParentheses/generateParentheses.cc)
      
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

add_executable(37
        leetcode/37-SudokuSolver/sudokuSolver.cc)

add_executable(39
        leetcode/39-CombinationSum/combinationSum.cc)
  
add_executable(42
        leetcode/42-TrappingRainWater/trappingRainWater.cc)

add_executable(53
        leetcode/53-MaximumSubarray/maximumSubarray.cc)

add_executable(54
        leetcode/54-SpiralMatrix/spiralMatrix.cc)

add_executable(62
  leetcode/62-UniquePaths/uniquePaths.cc)

add_executable(78
  leetcode/78-Subsets/subsets.cc)

add_executable(70
  leetcode/70-ClimbingStairs/climbingStairs.cc)

add_executable(76
  leetcode/76-MinimumWindowSubstring/minimumWindowSubstring.cc
  leetcode/cppinclude/cpputility.h)
      
add_executable(77
  leetcode/77-Combinations/combinations.cc)
      
add_executable(88
  leetcode/88-MergeSortedArray/mergeSortedArray.cc)

add_executable(95
        leetcode/95-UniqueBinarySearchTreesII/uniqueBinarySearchTreesII.cc)
        
add_executable(98
        leetcode/98-ValidateBinarySearchTree/validateBinarySearchTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(99
        leetcode/99-RecoverBinarySearchTree/recoverBinarySearchTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(101
        leetcode/101-SymmetricTree/symmetricTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(103
        leetcode/103-BinaryTreeZigzagLevelOrderTraversal/binaryTreeZigzagLevelOrderTraversal.cc
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

add_executable(121
        leetcode/121-BestTimeToBuyAndSellStock/bestTimeToBuyAndSellStock.cc)

add_executable(122
        leetcode/122-BestTimetoBuyandSellStockII/bestTimetoBuyandSellStockII.cc)

add_executable(124
        leetcode/124-BinaryTreeMaximumPathSum/binaryTreeMaximumPathSum.cc
        leetcode/cppinclude/bt.cc)

add_executable(128
  leetcode/128-LongestConsecutiveSequence/longestConsecutiveSequence.cc)

add_executable(133
  leetcode/133-CloneGraph/cloneGraph.cc
  leetcode/cppinclude/graph_leetcode.h)

add_executable(140
  leetcode/140-WordBreakII/wordBreakII.cc)

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

add_executable(162
        leetcode/162-FindPeakElement/findPeakElement.cc)

add_executable(165
        leetcode/165-CompareVersionNumbers/compareVersionNumbers.c)

add_executable(186
        leetcode/186-ReverseWordsInAStringII/reverseWordsInAStringII.cc)

add_executable(189
  leetcode/189-RotateArray/rotateArray.cc)

add_executable(200
  leetcode/200-NumberOfIslands/numberOfIslands.cc
  leetcode/cppinclude/cpputility.h)

add_executable(204
        leetcode/204-CountPrimes/countPrimes.cc)

add_executable(207
        leetcode/207-CourseSchedule/courseSchedule.cc
        leetcode/cppinclude/graph.h
        leetcode/cppinclude/graph.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(208
        leetcode/208-ImplementTrie/implementTrie.cc)

add_executable(213
        leetcode/213-HouseRobberII/houseRobberII.cc)

add_executable(214
        leetcode/214-ShortestPalindrome/shortestPalindrome.cc)

add_executable(216
        leetcode/216-CombinationSumIII/combinationSumIII.cc)
      
add_executable(222
        leetcode/222-CountCompleteTreeNodes/countCompleteTreeNodes.cc
        leetcode/cppinclude/bt.cc)

add_executable(224
        leetcode/224-BasicCalculator/basicCalculator.cc)

add_executable(225
        leetcode/225-ImplementStackUsingQueues/implementStackUsingQueues.cc)
      
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

add_executable(238
        leetcode/238-ProductofArrayExceptSelf/productofArrayExceptSelf.cc)

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

add_executable(260
        leetcode/260-SingleNumberIII/singleNumberIII.cc)

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

add_executable(273
        leetcode/273-IntegerToEnglishWords/integerToEnglishWords.cc)

add_executable(274
        leetcode/274-H-index/h-index.cc)

add_executable(278
        leetcode/278-FirstBadVersion/firstBadVersion.cc)

add_executable(283
        leetcode/283-MoveZeroes/moveZeroes.cc)

add_executable(285
        leetcode/285-InorderSuccessorinBST/inorderSuccessorInBST.c
        leetcode/cinclude/bst.c)

add_executable(289
        leetcode/289-GameOfLife/gameOfLife.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(291
        leetcode/291-WordPatternII/wordPatternII.cc)

add_executable(294
  leetcode/294-FlipGameII/flipGameII.cc)
      
add_executable(295
        leetcode/295-FindMedianfromDataStream/findMedianfromDataStream.cc)

add_executable(297
        leetcode/297-SerializeandDeserializeBinaryTree/serializeandDeserializeBinaryTree.cc
        leetcode/cppinclude/bt.cc
        leetcode/cppinclude/cpputility.cc)

add_executable(298
        leetcode/298-BinaryTreeLongestConsecutiveSequence/binaryTreeLongestConsecutiveSequence.cc
        leetcode/cppinclude/bt.cc)

add_executable(301
  leetcode/301-RemoveInvalidParentheses/removeInvalidParentheses.cc)

add_executable(305
  leetcode/305-NumberOfIslandsII/numberOfIslandsII.cc)

add_executable(320
  leetcode/320-GeneralizedAbbreviation/generalizedAbbreviation.cc)

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

add_executable(362
        leetcode/362-DesignHitCounter/designHitCounter.cc)

add_executable(366
        leetcode/366-FindLeavesofBinaryTree/findLeavesofBinaryTree.cc
        leetcode/cppinclude/bt.cc)

add_executable(369
        leetcode/369-PlusOneLinkedList/plusOneLinkedList.cc
        leetcode/cppinclude/linkedList.cc)

add_executable(380
        leetcode/380-InsertDeleteGetRandomO1/insertDeleteGetRandomO1.cc)

add_executable(387
        leetcode/387-FirstUniqueCharacterinaString/firstUniqueCharacterinaString.cc)

add_executable(394
        leetcode/394-DecodeString/decodeString.cc)

add_executable(403
        leetcode/403-FrogJump/frogJump.cc)

add_executable(412
        leetcode/412-FizzBuzz/fizzBuzz.c)
        
add_executable(414
        leetcode/414-ThirdMaximumNumber/thirdMaximumNumber.cc)

add_executable(426
        leetcode/426-ConvertBinarySearchTreeToSortedDoublyLinkedList/convertBinarySearchTreeToSortedDoublyLinkedList.cc)

add_executable(437
        leetcode/437-PathSumIII/pathSumIII.cc
        leetcode/cppinclude/bt.cc)

add_executable(438
        leetcode/438-FindAllAnagramsInAString/findAllAnagramsInAString.cc)

add_executable(443
        leetcode/443-StringCompression/stringCompression.cc)

add_executable(451
        leetcode/451-SortCharactersByFrequency/sortCharactersByFrequency.cc)

add_executable(460
        leetcode/460-LFUCache/lFUCache.cc)

add_executable(463
        leetcode/463-IslandPerimeter/islandPerimeter.cc)

add_executable(567
        leetcode/567-PermutationInString/permutationInString.cc)

add_executable(582
  leetcode/582-KillProcess/killProcess.cc)

add_executable(609
  leetcode/609-FindDuplicateFileinSystem/findDuplicateFileinSystem.cc)

add_executable(632
  leetcode/632-SmallestRangeCoveringElementsfromKLists/smallestRangeCoveringElementsfromKLists.cc
  leetcode/cppinclude/cpputility.h)      

add_executable(636
  leetcode/636-ExclusiveTimeofFunctions/exclusiveTimeofFunctions.cc)
      
add_executable(658
        leetcode/658-FindKClosestElements/findKClosestElements.cpp)

add_executable(662
        leetcode/662-MaximumWidthOfBinaryTree/maximumWidthOfBinaryTree.cc
        leetcode/cppinclude/bt.cc)

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

add_executable(784
        leetcode/784-LetterCasePermutation/letterCasePermutation.cc)

add_executable(796
        leetcode/796-RotateString/rotateString.cc)

add_executable(797
        leetcode/797-AllPathsFromSourceToTarget/allPathsFromSourceToTarget.cc)

add_executable(811
        leetcode/811-SubdomainVisitCount/subdomainVisitCount.cc)

add_executable(829
        leetcode/829-ConsecutiveNumbersSum/consecutiveNumbersSum.cc)

add_executable(842
        leetcode/842-SplitArrayintoFibonacciSequence/splitArrayintoFibonacciSequence.cc)

add_executable(977
        leetcode/977-SquaresofaSortedArray/squaresofaSortedArray.cc)
      
add_executable(00
        leetcode/cppinclude/queue.tpp
        leetcode/cppinclude/queue.h
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

add_executable(016
        leetcode/cppinclude/segmentTree.cc)

add_executable(017
        misc/findAncestor/findAncestor.cc)

#add_executable(018
#        misc/RangeQueryForText/rangeQueryForText.cc)

configure_file(misc/BleedingInk/input001.txt input001.txt COPYONLY)
add_executable(019
        misc/BleedingInk/bleedingInk.cc)

add_executable(020
        misc/Arrays/main.c
        misc/Arrays/arrays.c)

add_executable(021
        misc/Fib/fib.c
        misc/Fib/list.h)

add_executable(022
        misc/FindMissing/find.c
        misc/FindMissing/main.c)

add_executable(023
        misc/Merge/merge.c
        misc/Merge/main.c)

add_executable(024
        misc/RemoveMatches/remove_matches.c
        misc/RemoveMatches/main.c
        misc/RemoveMatches/list.c)

add_executable(025
        misc/Vercmp/vercmp.c)

add_executable(026
        misc/Questions/c_programming.c)

add_executable(027
        misc/Questions/ptr_thing.c)

add_executable(028
        misc/Questions/performance.cpp)

add_executable(029
  misc/DictionaryTask/dictionary.cc
  misc/DictionaryTask/test.cc)

add_executable(030
  misc/FibNumber/fibNumber.cc)

add_executable(031
  misc/Quora2020/addStringdigits.cc)

add_executable(032
  misc/Quora2020/distinctTriplet.cc)

add_executable(033
  misc/Quora2020/sortdiagonal.cc
  leetcode/cppinclude/cpputility.h)

configure_file(hackerrank/IPAddressValidation/input001.txt input001.txt COPYONLY)
configure_file(hackerrank/IPAddressValidation/output001_exp.txt output001_exp.txt COPYONLY)
add_executable(034
  hackerrank/IPAddressValidation/ipAddressValidation.cc
  leetcode/cppinclude/cpputility.h)

add_executable(035
  misc/isValidISBN/isValidISBN.cc)

add_executable(036
  misc/Quora2020/goodTuple.cc
  leetcode/cppinclude/cpputility.h)
