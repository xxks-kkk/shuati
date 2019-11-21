project(shuati/leetcode)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_DIR}/misc)

add_executable(00
  ${INCLUDE_DIR}/cppinclude/queue.tpp
  ${INCLUDE_DIR}/cppinclude/queue.h
  QueueArrayImplementation/queueArrayImplementation.cc)
target_include_directories(00 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(001
  GetFruits/getFruits.cc)

add_executable(002
  HDRT/simplePrint.c)

add_executable(003
  ReformattingDates/reformattingDates.cc)

configure_file(MaximizingProfitFromStocks/input.txt input004.txt COPYONLY)
add_executable(004
  MaximizingProfitFromStocks/maximizingProfitFromStocks.cc)

add_executable(005
  IsThisATree/isThisATree.cc)

add_executable(006
  FindTheWinner/findTheWinner.cc)

add_executable(007
  SmartSale/smartSale.cc)

add_executable(008
  WebsitePagination/websitePagination.cc)

add_executable(009
  RemovingChocolates/removingChocolates.cc)

add_executable(010
  ConsecutiveSum/consecutiveSum.cc)

add_executable(011
  ThePerfectTeam/thePerfectTeam.cc)

add_executable(012
  WorkSchedule/workSchedule.cc)

add_executable(013
  MergeString/mergeString.cc)

add_executable(014
  BudgetShopping/budgetShopping.cc)

add_executable(015
  DistinctPairs/distinctPairs.cc)

add_executable(016
  ${INCLUDE_DIR}/cppinclude/segmentTree.cc)
target_include_directories(016 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(017
  findAncestor/findAncestor.cc)

#add_executable(018
#  RangeQueryForText/rangeQueryForText.cc)

configure_file(BleedingInk/input001.txt input001.txt COPYONLY)
add_executable(019
  BleedingInk/bleedingInk.cc)

add_executable(020
  Arrays/main.c
  Arrays/arrays.c)

add_executable(021
  Fib/fib.c
  Fib/list.h)

add_executable(022
  FindMissing/find.c
  FindMissing/main.c)

add_executable(023
  Merge/merge.c
  Merge/main.c)

add_executable(024
  RemoveMatches/remove_matches.c
  RemoveMatches/main.c
  RemoveMatches/list.c)

add_executable(025
  Vercmp/vercmp.c)

add_executable(026
  Arista/c_programming.c)

add_executable(027
  Arista/ptr_thing.c)

add_executable(028
  Arista/performance.cpp)

add_executable(029
  DictionaryTask/dictionary.cc
  DictionaryTask/test.cc)

add_executable(030
  FibNumber/fibNumber.cc)

add_executable(031
  Quora2020/addStringdigits.cc)

add_executable(032
  Quora2020/distinctTriplet.cc)

add_executable(033
  Quora2020/sortdiagonal.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(033 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(035
  isValidISBN/isValidISBN.cc)

add_executable(036
  Quora2020/goodTuple.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(036 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(037
  Quora2020/validLetters.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(037 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(038
  Quora2020/rotataMatrixAmongDiagonals.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(038 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(039
  Quora2020/cutRibbon.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(039 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(040
  Quora2020/divisorSubstring.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(040 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(041
  Quora2020/divideArray.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(041 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(042
  Quora2020/coolFeature.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(042 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(043
  Amazon/buyFruits.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(043 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(044
  Amazon/scoreGathering.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(044 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(045
  Amazon/distBetweenNodes.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(045 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(046
  Amazon/prioritizedOrders/prioritizedOrders.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.h)
target_include_directories(046 PRIVATE ${INCLUDE_DIR}/cppinclude)

add_executable(047
  Amazon/minimumDistance/minimumDistance.cc
  ${INCLUDE_DIR}/cppinclude/cpputility.cc)
target_include_directories(047 PRIVATE ${INCLUDE_DIR}/cppinclude)
