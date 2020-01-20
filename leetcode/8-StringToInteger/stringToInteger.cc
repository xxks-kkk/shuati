#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    if(str.empty())
      return 0;

    // remove whitespaces
    int i = 0;
    while(i < str.size() && str[i] == ' ')
      ++i;

    // after whitespace removal if the first character is anything
    // other than +,-,[0-9]
    char first_char = str[i++];
    bool negative = false;
    int result = 0;

    if(first_char != '-' && first_char != '+' &&
       ((first_char - '0') < 0  || (first_char - '0') > 9) )
      return 0;

    // set sign
    negative = first_char == '-';
    // if first char is a digit instead of sign
    result = ((first_char - '0') >= 0  && (first_char - '0') <= 9) ? (first_char - '0') : 0;

    // construct the remaining number using chars
    // if the final number is negative then each time we add negative digits
    // this makes it possible to save it in 32-bit int otherwise overflow occurs
    while(i < str.size() && isdigit(str[i])) {
      int curr_digit = str[i] - '0';

      // check if the number goees beyond negative LIMIT
      if(negative && (result < (INT_MIN + curr_digit) / 10))
        return INT_MIN;
        // check if the number goees beyond positive LIMIT
      else if(!negative && (result > (INT_MAX - curr_digit)/10))
        return INT_MAX;

      // make the current digit negative in case of negative number is final result
      if(negative)
        curr_digit *= -1;
      result = result*10 + curr_digit;
      ++i;
    }
    return result;
  }
};

using ptr2myAtoi = int (Solution::*)(string);

void test(ptr2myAtoi pfcn)
{
  Solution sol;
  struct testCase
  {
    string input;
    int expected;
  };
  vector<testCase> test_cases = {
      {"42", 42},
      {"   -42", -42},
      {"4193 with words", 4193},
      {"words and 987", 0},
      {"-91283472332", -2147483648},
      {"-000000000000001", -1},
      {"+-2", 0},
      {"010", 10},
      {"  -0012a42", -12},
      {"-01324000", -1324000},
  };
  for (auto &&test_case : test_cases)
  {
    auto got = (sol.*pfcn)(test_case.input);
    if (got != test_case.expected)
    {
      printf("%s(%s) = %d\n",
             "myAtoi",
             test_case.input.c_str(),
             got);
      assert(false);
    }
  }
}

int main()
{
  ptr2myAtoi pfcn = &Solution::myAtoi;
  test(pfcn);
}
