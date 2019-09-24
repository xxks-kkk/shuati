#include <vector>
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
  // Implementation based on assumption that it is adding two string numbers
  // Ex: "19" + "22" gives "41" instead of "311" provided by leaked OA  
  string addStringDigits(string s1, string s2) {
    string res = "";
    int ptr1 = s1.length() - 1;
    int ptr2 = s2.length() - 1;
    int reminder = 0;
    int num = 0;
    int quotient = 0;
    while (ptr1 >= 0 && ptr2 >= 0) {
      num = (s1[ptr1] - '0') + (s2[ptr2] - '0') + quotient;
      reminder = num % 10;
      quotient = num / 10;
      res.insert(0, to_string(reminder));
      ptr1--;
      ptr2--;
    }
    while (ptr1 >= 0) {
      num = (s1[ptr1] - '0') + quotient;
      reminder = num % 10;
      quotient = num / 10;
      res.insert(0, to_string(reminder));
      ptr1--;
    }
    while (ptr2 >= 0) {
      num = (s2[ptr2] - '0') + quotient;
      reminder = num % 10;
      quotient = num / 10;
      res.insert(0, to_string(reminder));
      ptr2--;
    }
    if (quotient != 0) {
      res.insert(0, to_string(quotient));
    }
    return res;
  }

  // The implementation based on the actual leaked OA examples
  string addStringDigits2(string s1, string s2) {
    string res = "";
    int ptr1 = s1.length() - 1;
    int ptr2 = s2.length() - 1;
    int reminder = 0;
    int num = 0;
    int quotient = 0;
    while (ptr1 >= 0 && ptr2 >= 0) {
      num = (s1[ptr1] - '0') + (s2[ptr2] - '0') + quotient;
      res.insert(0, to_string(num));
      ptr1--;
      ptr2--;
    }
    while (ptr1 >= 0) {
      num = (s1[ptr1] - '0');
      res.insert(0, to_string(num));
      ptr1--;
    }
    while (ptr2 >= 0) {
      num = (s2[ptr2] - '0') + quotient;
      res.insert(0, to_string(num));
      ptr2--;
    }
    return res;    
  }
};

using ptr2addStringDigits = string (Solution::*)(string s1, string s2);

class Test {
public:
  // This tests "addStringDigits", which I assume it is adding two string numbers
  // Ex: "19" + "22" gives "41" instead of "311" provided by leaked OA
  void test_pfcn(ptr2addStringDigits pfcn) {
    Solution sol;
    struct testCase {
      string a;
      string b;
      string expected;
    };
    vector<testCase> test_cases = {
      { "19", "22", "41"},
      { "20", "2032", "2052"}
    };
    for(auto && test_case: test_cases) {
      string res = (sol.*pfcn)(test_case.a, test_case.b);
      if (res != test_case.expected) {
        printf("addStringDigits(%s, %s) = %s\n", test_case.a.c_str(), test_case.b.c_str(), res.c_str());
      }
    }
  }

  void test_addStringDigits2() {
    Solution sol;
    struct testCase {
      string a;
      string b;
      string expected;
    };
    vector<testCase> test_cases = {
      { "19", "22", "311"},
      { "20", "2032", "2052"}
    };
    for(auto && test_case: test_cases) {
      string res = (sol.addStringDigits2)(test_case.a, test_case.b);
      if (res != test_case.expected) {
        printf("addStringDigits2(%s, %s) = %s\n", test_case.a.c_str(), test_case.b.c_str(), res.c_str());
      }
    }
  }
};

int main() {
  Test test;
  ptr2addStringDigits pfcn = &Solution::addStringDigits;
  test.test_pfcn(pfcn);
  test.test_addStringDigits2();
}
