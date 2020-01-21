project(shuati/leetcode)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_DIR}/leetcode)
set(CMAKE_JAVA_TARGET_OUTPUT_DIR ${CMAKE_BUILD_DIR}/leetcode/Java)

add_jar(1_JAVA ${PROJECT_SOURCE_DIR}/1-TwoSum/TwoSum.java)
add_test(NAME TwoSum.java COMMAND ${Java_JAVA_EXECUTABLE} -cp ${CMAKE_JAVA_TARGET_OUTPUT_DIR}/1_JAVA.jar TwoSum)

add_executable(2
  2-AddTwoNumbers/addTwoNumbers.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(2 PRIVATE ${INCLUDE_DIR}/cppinclude)
add_test(NAME addTwoNumbers.cc COMMAND 2)

add_executable(4
  4-MedianofTwoSortedArrays/medianofTwoSortedArrays.cc)
target_include_directories(4 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(5
  5-LongestPalindromicSubstring/longestPalindromicSubstring.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(5 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(8
  8-StringToInteger/stringToInteger.cc)
add_test(NAME stringToInteger.cc COMMAND 8)

add_executable(9
  9-PalindromeNumber/palindromeNumber.cc)

add_executable(10
  10-RegularExpressionMatching/regularExpressionMatching.cc)

add_executable(14
  14-LongestCommonPrefix/longestCommonPrefix.cc
  ${INCLUDE_DIR}/cppinclude/trie.h
  ${INCLUDE_DIR}/cppinclude/trie.cc)
target_include_directories(14 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(20
  20-ValidParentheses/validParentheses.cc)

add_executable(21
  21-MergeTwoSortedList/mergeTwoSortedList.c
  ${INCLUDE_DIR}/cinclude/linkedlist.c)
target_include_directories(21 PRIVATE ${INCLUDE_DIR}/cinclude)

add_executable(21-cpp
  21-MergeTwoSortedList/mergeTwoSortedList.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.cc)
target_include_directories(21-cpp PRIVATE ${INCLUDE_DIR}/cppinclude)
add_test(NAME mergeTwoSortedList.cc COMMAND make 21-cpp)

add_executable(22
  22-GenerateParentheses/generateParentheses.cc)
      
add_executable(23
  23-MergekSortedLists/mergekSortedLists.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(23 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(25
  25-ReverseNodesink-Group/reverseNodesink-Group.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.h)
target_include_directories(25 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(27
  27-RemoveElement/removeElement.cc)

add_executable(30
  30-SubstringwithConcatenationofAllWords/substringwithConcatenationofAllWords.cc)

add_executable(32
  32-LongestValidParentheses/longestValidParentheses.cc)

add_executable(33
  33-SearchInRotatedSortedArray/searchInRotatedSortedArray.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(33 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(35
  35-SearchInsertPosition/searchInsertPosition.cc)

add_executable(37
  37-SudokuSolver/sudokuSolver.cc)

add_executable(39
  39-CombinationSum/combinationSum.cc)
  
add_executable(42
  42-TrappingRainWater/trappingRainWater.cc)

add_executable(53
  53-MaximumSubarray/maximumSubarray.cc)

add_executable(54
  54-SpiralMatrix/spiralMatrix.cc)

add_executable(56
  56-MergeIntervals/mergeIntervals.cpp
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(56 PRIVATE ${INCLUDE_DIR}/cppinclude)
      
add_executable(62
  62-UniquePaths/uniquePaths.cc)

add_executable(75
  75-SortColors/sortColors.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(75 PRIVATE ${INCLUDE_DIR}/cppinclude)
add_test(NAME sortColors.cc COMMAND 75)

add_executable(78
  78-Subsets/subsets.cc)

add_executable(70
  70-ClimbingStairs/climbingStairs.cc)

add_executable(76
  76-MinimumWindowSubstring/minimumWindowSubstring.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(76 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(77
  77-Combinations/combinations.cc)
      
add_executable(88
  88-MergeSortedArray/mergeSortedArray.cc)

add_executable(95
  95-UniqueBinarySearchTreesII/uniqueBinarySearchTreesII.cc
  ${INCLUDE_DIR}/cppinclude/bt.h)
target_include_directories(95 PRIVATE ${INCLUDE_DIR}/cppinclude)
        
add_executable(98
  98-ValidateBinarySearchTree/validateBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(98 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(99
  99-RecoverBinarySearchTree/recoverBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(99 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(101
  101-SymmetricTree/symmetricTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(101 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(102
  102-BinaryTreeLevelOrderTraversal/binaryTreeLevelOrderTraversal.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(102 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(103
  103-BinaryTreeZigzagLevelOrderTraversal/binaryTreeZigzagLevelOrderTraversal.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(103 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(107
  107-BinaryTreeLevelOrderTraversalII/binaryTreeLevelOrderTraversalII.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(107 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(108
  108-ConvertSortedArraytoBinarySearchTree/convertSortedArraytoBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(108 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(110
  110-BalancedBinaryTree/balancedBinaryTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(110 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(121
  121-BestTimeToBuyAndSellStock/bestTimeToBuyAndSellStock.cc)

add_executable(122
  122-BestTimetoBuyandSellStockII/bestTimetoBuyandSellStockII.cc)

add_executable(124
  124-BinaryTreeMaximumPathSum/binaryTreeMaximumPathSum.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(124 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(128
  128-LongestConsecutiveSequence/longestConsecutiveSequence.cc)

add_executable(133
  133-CloneGraph/cloneGraph.cc
  ${INCLUDE_DIR}/cppinclude/graph_leetcode.h)
target_include_directories(133 PRIVATE ${INCLUDE_DIR}/cppinclude)

#TODO: is there a way to include jsoncpp.cpp automatically whenever we include
# the .cc that has dependency on it (e.g., linkedList_rand.cc)
add_executable(138
  138-CopyListWithRandomPointer/copyListWithRandomPointer.cc
  ${INCLUDE_DIR}/cppinclude/linkedList_rand.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h
  ${THIRD_PARTY_INCLUDE_DIR}/jsoncpp/jsoncpp.cpp)
target_include_directories(138 PRIVATE ${INCLUDE_DIR}/cppinclude ${THIRD_PARTY_INCLUDE_DIR}/jsoncpp)

add_executable(140
  140-WordBreakII/wordBreakII.cc)

add_executable(141
  141-LinkedListCycle/linkedListCycle.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(141 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(145
  145-BinaryTreePostorderTraversal/binaryTreePostorderTraversal.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(145 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(146
  146-LRUCache/lRUCache.cc)

add_executable(155
  155-MinStack/minStack.cc)

add_executable(159
  159-LongestSubstringWithAtMostTwoDistinctCharacters/longestSubstringWithAtMostTwoDistinctCharacters.cc)

add_executable(160
  160-IntersectionofTwoLinkedLists/intersectionofTwoLinkedLists.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(160 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(162
  162-FindPeakElement/findPeakElement.cc)

add_executable(165
  165-CompareVersionNumbers/compareVersionNumbers.c)

add_executable(186
  186-ReverseWordsInAStringII/reverseWordsInAStringII.cc)

add_executable(189
  189-RotateArray/rotateArray.cc)

add_executable(200
  200-NumberOfIslands/numberOfIslands.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(200 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(204
  204-CountPrimes/countPrimes.cc)

add_executable(207
  207-CourseSchedule/courseSchedule.cc
  ${INCLUDE_DIR}/cppinclude/graph.h
  ${INCLUDE_DIR}/cppinclude/graph.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.cc)
target_include_directories(207 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(208
  208-ImplementTrie/implementTrie.cc)

add_executable(210
  210-CourseScheduleII/courseScheduleII.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(210 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(213
  213-HouseRobberII/houseRobberII.cc)

add_executable(214
  214-ShortestPalindrome/shortestPalindrome.cc)

add_executable(216
  216-CombinationSumIII/combinationSumIII.cc)
      
add_executable(222
  222-CountCompleteTreeNodes/countCompleteTreeNodes.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(222 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(224
  224-BasicCalculator/basicCalculator.cc)

add_executable(225
  225-ImplementStackUsingQueues/implementStackUsingQueues.cc)
      
add_executable(230
  230-KthSmallestElementinaBST/kthSmallestElementinaBST.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(230 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(232
  232-ImplementQueueusingStacks/implementQueueusingStacks.cc)

add_executable(234
  234-PalindromeLinkedList/palindromeLinkedList.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(234 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(235
  235-LowestCommonAncestorofaBinarySearchTree/lowestCommonAncestorofaBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc)
target_include_directories(235 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(236
  236-LowestCommonAncestorOfABinaryTree/lowestCommonAncestorOfABinaryTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(236 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(238
  238-ProductofArrayExceptSelf/productofArrayExceptSelf.cc)

add_executable(240
  240-Searcha2DMatrixII/searcha2DMatrixII.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(240 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(242
  242-ValidAnagram/validAnagram.cc)

add_executable(250
  250-CountUnivalueSubtrees/countUnivalueSubtrees.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(250 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(253
  253-MeetingRoomsII/meetingRoomsII.cc)

add_executable(255
  255-VerifyPreorderSequenceinBinarySearchTree/verifyPreorderSequenceinBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc)
target_include_directories(255 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(257
  257-BinaryTreePaths/binaryTreePaths.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(257 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(260
  260-SingleNumberIII/singleNumberIII.cc)

add_executable(261
  261-GraphValidTree/graphValidTree.cc)

add_executable(268
  268-MissingNumber/missingNumber.cc)

add_executable(270
  270-ClosestBinarySearchTreeValue/closestBinarySearchTreeValue.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc)
target_include_directories(270 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(272
  272-ClosestBinarySearchTreeValueII/closestBinarySearchTreeValueII.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc)
target_include_directories(272 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(273
  273-IntegerToEnglishWords/integerToEnglishWords.cc)

add_executable(274
  274-H-index/h-index.cc)

add_executable(278
  278-FirstBadVersion/firstBadVersion.cc)

add_executable(283
  283-MoveZeroes/moveZeroes.cc)

add_executable(285
  285-InorderSuccessorinBST/inorderSuccessorInBST.c
  ${INCLUDE_DIR}/cinclude/bst.c)
target_include_directories(285 PRIVATE ${INCLUDE_DIR}/cinclude)

configure_file(289-GameOfLife/input.txt input289.txt COPYONLY)
add_executable(289
  289-GameOfLife/gameOfLife.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.cc)
target_include_directories(289 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(291
  291-WordPatternII/wordPatternII.cc)

add_executable(294
  294-FlipGameII/flipGameII.cc)
      
add_executable(295
  295-FindMedianfromDataStream/findMedianfromDataStream.cc)

add_executable(297
  297-SerializeandDeserializeBinaryTree/serializeandDeserializeBinaryTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.cc)
target_include_directories(297 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(298
  298-BinaryTreeLongestConsecutiveSequence/binaryTreeLongestConsecutiveSequence.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(298 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(301
  301-RemoveInvalidParentheses/removeInvalidParentheses.cc)

add_executable(305
  305-NumberOfIslandsII/numberOfIslandsII.cc)

add_executable(320
  320-GeneralizedAbbreviation/generalizedAbbreviation.cc)

add_executable(322
  322-CoinChange/coinChange.cc)

add_executable(333
  333-LargestBSTSubtree/largestBSTSubtree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(333 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(337
  337-HouseRobberIII/houseRobberIII.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(337 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(344
  344-ReverseString/reverseString.cc)

add_executable(346
  346-MovingAveragefromDataStream/movingAveragefromDataStream.cc)

add_executable(347
  347-TopKFrequentElements/topKFrequentElements.cc)

add_executable(349
  349-IntersectionOfTwoArrays/intersectionOfTwoArrays.cc)

add_executable(350
  350-IntersectionofTwoArraysII/intersectionofTwoArraysII.cc)

add_executable(362
  362-DesignHitCounter/designHitCounter.cc)

add_executable(366
  366-FindLeavesofBinaryTree/findLeavesofBinaryTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(366 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(369
  369-PlusOneLinkedList/plusOneLinkedList.cc
  ${INCLUDE_DIR}/cppinclude/linkedList.cc)
target_include_directories(369 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(380
  380-InsertDeleteGetRandomO1/insertDeleteGetRandomO1.cc)

add_executable(387
  387-FirstUniqueCharacterinaString/firstUniqueCharacterinaString.cc)

add_executable(394
  394-DecodeString/decodeString.cc)

add_executable(403
  403-FrogJump/frogJump.cc)

add_executable(412
  412-FizzBuzz/fizzBuzz.c)
        
add_executable(414
  414-ThirdMaximumNumber/thirdMaximumNumber.cc)

add_executable(426
  426-ConvertBinarySearchTreeToSortedDoublyLinkedList/convertBinarySearchTreeToSortedDoublyLinkedList.cc)

add_executable(437
  437-PathSumIII/pathSumIII.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(437 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(438
  438-FindAllAnagramsInAString/findAllAnagramsInAString.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(438 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(443
  443-StringCompression/stringCompression.cc)

add_executable(451
  451-SortCharactersByFrequency/sortCharactersByFrequency.cc)

add_executable(460
  460-LFUCache/lFUCache.cc)

add_executable(463
  463-IslandPerimeter/islandPerimeter.cc)

add_executable(490
  490-TheMaze/theMaze.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(490 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(505
  505-TheMazeII/theMazeII.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(505 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(509
  509-FibonacciNumber/fibonacciNumber.cc)

add_executable(535
  535-EncodeandDecodeTinyURL/encodeandDecodeTinyURL.cc)

add_executable(567
  567-PermutationInString/permutationInString.cc)

add_executable(582
  582-KillProcess/killProcess.cc)

add_executable(609
  609-FindDuplicateFileinSystem/findDuplicateFileinSystem.cc)

add_executable(632
  632-SmallestRangeCoveringElementsfromKLists/smallestRangeCoveringElementsfromKLists.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(632 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(636
  636-ExclusiveTimeofFunctions/exclusiveTimeofFunctions.cc)

add_executable(647
  647-PalindromicSubstrings/palindromicSubstrings.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(647 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(658
  658-FindKClosestElements/findKClosestElements.cpp)

add_executable(662
  662-MaximumWidthOfBinaryTree/maximumWidthOfBinaryTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(662 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(663
  663-EqualTreePartition/equalTreePartition.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc)
target_include_directories(663 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(669
  669-TrimaBinarySearchTree/trimaBinarySearchTree.cc
  ${INCLUDE_DIR}/cppinclude/bt.cc
  ${INCLUDE_DIR}/cppinclude/bst.cc)
target_include_directories(669 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(675
  675-CutOffTreesforGolfEvent/cutOffTreesforGolfEvent.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(675 PRIVATE ${INCLUDE_DIR}/cppinclude)
        
add_executable(704
  704-BinarySearch/binarySearch.cc)

add_executable(739
  739-DailyTemperatures/dailyTemperatures.cc)

add_executable(784
  784-LetterCasePermutation/letterCasePermutation.cc)

add_executable(796
  796-RotateString/rotateString.cc)

add_executable(797
  797-AllPathsFromSourceToTarget/allPathsFromSourceToTarget.cc)

add_executable(811
  811-SubdomainVisitCount/subdomainVisitCount.cc)

add_executable(829
  829-ConsecutiveNumbersSum/consecutiveNumbersSum.cc)

add_executable(842
  842-SplitArrayintoFibonacciSequence/splitArrayintoFibonacciSequence.cc)

add_executable(977
  977-SquaresofaSortedArray/squaresofaSortedArray.cc)

add_executable(1114
  1114-PrintInOrder/printInOrder.cc
  ${INCLUDE_DIR}/cppinclude/mysemaphore.cc)
target_include_directories(1114 PRIVATE ${INCLUDE_DIR}/cppinclude)
