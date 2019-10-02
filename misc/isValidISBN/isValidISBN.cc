// EA Cloud team (10/01/19) by Jeff Carter
#include <string>
#include <vector>
#include <stdio.h>
#include <cassert>

using namespace std;

bool isValidISBN(string& isbn) {
  int n = isbn.length();
  if (n != 10 && n != 13) return false;
  if (isbn[0] == '-' || isbn[n-1] == '-') return false;
  int sum = 0;
  int num_dashes = 0;
  int num_count = 0;
  int digit = 0;
  for(int i = 0; i < n-1; ++i) {
    if (isbn[i] == '-' && isbn[i+1] == '-') return false;
    if (isbn[i] == '-') {
      num_dashes++;
    } else {
      num_count++;
      digit = isbn[i] - '0';
      if (0 > digit || digit > 9) return false;
      sum += (digit * num_count);
    }
  }
  if (num_dashes != 0 && num_dashes != 3) {
    return false;
  }
  char last = isbn[n-1];
  if (last != 'X' && last != 'x' && (last > '9' || last < '0')) return false;
  int last_digit_num;
  if (last == 'X' || last == 'x') {
    last_digit_num = 10;
  } else {
    last_digit_num = last - '0';
  }
  return (sum % 11 == last_digit_num);
}

int main() {
  struct testCase {
    string isbn;
    bool expected;
  };
  vector<testCase> test_cases = {
    {"0-9758419-7-1", true},
    {"0-321-42330-5", true},
    {"0-9752298-0-X", true},
    {"123--456789-3", false},
  };
  for(auto&& test_case: test_cases) {
    bool got = isValidISBN(test_case.isbn);
    if (got != test_case.expected) {
      printf("isValidISBN(%s) = %s\n", test_case.isbn.c_str(), got == false? "false": "true");
      assert(false);
    }
  }
}
