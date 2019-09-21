#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
  vector<string> generateAbbreviations(string word) {
      vector<string> res;
      vector<int> cand;
      backtrack(res, cand, word);
      return res;
  }  
private:
  void backtrack(vector<string>& res, vector<int>& cand, string word) {
    if (cand.size() == word.length()) {
      res.push_back(convert2String(cand, word));
      return;
    }
    vector<int> choices = {1, 0};
    for(auto&& choice: choices) {
      cand.push_back(choice);
      backtrack(res, cand, word);
      cand.pop_back();
    }
  }

  // convert2String takes `cand` which is a vector consisting of 0 or 1
  // and generate new string based on `cand` and given word.
  string convert2String(vector<int> cand, string word) {
    // The generation rule:
    // 凡是0的地方都是原来的字母，单独的1还是1，如果是若干个1连在一起的话，就要求出1的个数，用这个数字来替换对应的字母
    int cnt = 0;
    string res = "";
    for(int i = 0; i < cand.size(); ++i) {
      if (cand[i] == 1) {
        cnt++;
        if (i == word.size() - 1) {
          res += to_string(cnt);
        }
      } else {
        if (cnt != 0) {
          res += to_string(cnt);
          cnt = 0;
        }
        res += word[i];
      }
    }
    return res;
  }

  friend class Test;
};

using ptr2generateAbbreviations = vector<string> (Solution::*)(string);

class Test {
public:
  void test_convert2String() {
    Solution sol;
    struct testCase {
      vector<int> cand;
      string word;
      string expected;
    };
    vector<testCase> test_cases = {
      {{0,0,0,0}, "word", "word"},
      {{0,0,0,1}, "word", "wor1"},
      {{0,0,1,1}, "word", "wo2"},
      {{1,1,0,1,1}, "wordz", "2r2"},
    };
    for(auto && test_case: test_cases) {
      string got = (sol.convert2String)(test_case.cand, test_case.word);
      if (got != test_case.expected) {
        string cand_str = "[";
        for(auto && item: test_case.cand) {
          cand_str += to_string(item);
          cand_str += ", ";
        }
        cand_str += "]";
        printf("convert2String(%s, %s) = %s \t expected: %s\n",
               cand_str.c_str(),
               test_case.word.c_str(),
               got.c_str(),
               test_case.expected.c_str());
      }
    }
  }

  void test_pfcn(ptr2generateAbbreviations pfcn) {
    Solution sol;
    struct testCase {
      string word;
      vector<string> expected;
    };
    vector<testCase> test_cases = {
      {"word", {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"}},
      {"exe", {"3","2e","1x1","1xe","e2","e1e","ex1","exe"}}
    };
    for(auto && test_case: test_cases) {
      vector<string> got = (sol.*pfcn)(test_case.word);
      for(auto&& item: got) {
        if (find(test_case.expected.begin(), test_case.expected.end(), item) == test_case.expected.end())
        {
          assert(false);
        }
      }
    }
  }    
};

int main() {
  Test test;
  test.test_convert2String();
  ptr2generateAbbreviations pfcn = &Solution::generateAbbreviations;
  test.test_pfcn(pfcn);
}
