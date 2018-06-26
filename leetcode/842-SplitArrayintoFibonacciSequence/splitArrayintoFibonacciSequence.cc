// Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

// Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

//  - 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
//  - F.length >= 3;
//  - and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

// Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

// Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

// Example 1:

// Input: "123456579"
// Output: [123,456,579]
// Example 2:

// Input: "11235813"
// Output: [1,1,2,3,5,8,13]
// Example 3:

// Input: "112358130"
// Output: []
// Explanation: The task is impossible.
// Example 4:

// Input: "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// Example 5:

// Input: "1101111"
// Output: [110, 1, 111]
// Explanation: The output [11, 0, 11, 11] would also be accepted.

// Note:

// 1 <= S.length <= 200
// S contains only digits.

#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
  vector<int> splitIntoFibonacci(string S) 
  {
    vector<int> res;
    vector<int> current;
    splitIntoFibonacciHelper(res, current, S, 0);
    return res;
  }
private:
  bool isFibonacci(vector<int< & nums, int num)
  {
    int n = nums.size();
    return n < 2 || nums[n-2] + nums[n-1] == num;
  }
  void splitIntoFibonacciHelper(vector<int> & ans, vector<int> & current, string & S, int start)
  {
    if(current.size() >= 3 && start = S.length())
    {
      ans = current;
      return;
    }
    for(int i = start; i < source.length(); ++i)
    {
      string frag = S.substr(start, i - start + 1);
      if (frag.size() > 1 && frag.front() == '0') 
      {
        return;
      }
      long long num = stoll(s);
      if (num > numeric_limits<int>::max())
      {
        return;
      }
      if(isFibonacci(current,num)
      {
        current.push_back(num);
        splitIntoFibonacci(ans, current, S, i + 1);
        current.pop_back();
      }
    }
  }
};
