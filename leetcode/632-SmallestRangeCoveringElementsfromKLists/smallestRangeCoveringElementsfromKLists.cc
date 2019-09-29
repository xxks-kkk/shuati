// You have k lists of sorted integers in ascending order. Find the smallest range that
// includes at least one number from each of the k lists.

// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c

// Example 1:
// Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

// Note:
//     The given list may contain duplicates, so ascending order means >= here.
//     1 <= k <= 3500
//     -105 <= value of elements <= 105.
                                                                          
#include <vector>
#include <limits>
#include <stdio.h>
#include "cpputility.h"
#include <cassert>
#include <unordered_map>

#define FUNC_DEF(func) { func, #func },

using namespace std;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> res;
    vector<pair<int, int>> cand; // vector<pair<num in the list with list_label, list_label>>
    unordered_map<int, int> m;   // unordered_map<list_label, count of list_label appearance>
    int diff = numeric_limits<int>::max();
    int num_lists = nums.size();    
    for(int i = 0; i < num_lists; ++i) {
      for(auto&& num: nums[i]) {
        cand.push_back(make_pair(num, i));
      }
    }
    sort(cand.begin(), cand.end());
    int left_ptr = 0;
    int right_ptr;
    int count = 0; // count the number of distinct list label appearance
    for(right_ptr = 0; right_ptr < cand.size(); ++right_ptr) {
      if (m[cand[right_ptr].second] == 0) count++;
      m[cand[right_ptr].second]++;
      while(count == num_lists && left_ptr <= right_ptr) {
        int lower_bound = cand[left_ptr].first;
        int upper_bound = cand[right_ptr].first;
        int interval_diff = upper_bound - lower_bound;
        if (diff > interval_diff) {
          diff = interval_diff;
          res = {lower_bound, upper_bound};
        }
        if(--m[cand[left_ptr].second] == 0) count--;
        left_ptr++;
      }
    }
    return res;
  }
};

using ptr2smallestRange = vector<int> (Solution::*)(vector<vector<int>>&);

struct testFuncsInfo {
  ptr2smallestRange pfcn;
  const char* pfcn_name;
};

void test(ptr2smallestRange pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> nums;
    vector<int> expected;
  };
  vector<testCase> test_cases = {
    {{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}}, {20,24}},
    {{{4,5},{4,4}}, {4,4}},
    {{{1,2,3},{1,2,3},{1,2,3}}, {1,1}},
    {{{10},{11}}, {10,11}},
    {{{1,3,5,7,9,10},{2,4,6,8,10}},{10,10}},
    {{{11,38,83,84,84,85,88,89,89,92},
      {28,61,89},
      {52,77,79,80,81},
      {21,25,26,26,26,27},
      {9,83,85,90},
      {84,85,87},
      {26,68,70,71},
      {36,40,41,42,45},
      {-34,21},
      {-28,-28,-23,1,13,21,28,37,37,38},
      {-74,1,2,22,33,35,43,45},
      {54,96,98,98,99},
      {43,54,60,65,71,75},
      {43,46},
      {50,50,58,67,69},
      {7,14,15},
      {78,80,89,89,90},
      {35,47,63,69,77,92,94}}, {15,84}},
  };
  for(auto&& test_case: test_cases) {
    vector<int> get = (sol.*pfcn)(test_case.nums);
    if (get != test_case.expected) {
      printf("%s(%s) = %s\n", pfcn_name,
             CPPUtility::twoDVectorStr(test_case.nums).c_str(),
             CPPUtility::oneDVectorStr(get).c_str());
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::smallestRange)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
