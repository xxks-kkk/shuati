#include <vector>
#include "cpputility.h"
#include <unordered_map>
#include <ctype.h> // for isalpha()
#include <string>

using namespace std;

class Solution {
public:
  int validLetters(vector<string>& words, vector<char>& valid_letter) {
    unordered_map<char, int> m;
    int count = words.size();
    for(auto&& c: valid_letter) {
      m[c]++;
    }
    for(auto&& word: words) {
      for(auto&& c: word) {
        if (isalpha(c) && m.find(tolower(c)) == m.end()) {
          count--;
          break;
        }
      }
    }
    return count;
  }
};


class Test {
public:
  void test_validLetters() {
    Solution sol;
    struct testCase {
      vector<string> words;
      vector<char> valid_letter;
      int expected;
    };
    vector<testCase> test_cases = {
      {{"hEllo##", "This^^"}, {'h', 'e', 'l', 'o', 't', 'h', 's'}, 1},
    };
    for(auto&& test_case: test_cases) {
      int got = sol.validLetters(test_case.words, test_case.valid_letter);
      if (got != test_case.expected) {
        printf("validLetters(%s, %s) = %d\n",
               CPPUtility::oneDVectorStr<string>(test_case.words).c_str(),
               CPPUtility::oneDVectorStr<char>(test_case.valid_letter).c_str(),
               got);
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_validLetters();
}
