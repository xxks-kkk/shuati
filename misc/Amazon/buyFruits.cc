#include "cpputility.h"
#include <unordered_map>

using namespace std;

void dfs(vector<string>& tmp,
         vector<vector<string>>& res,
         const vector<string>& fruits,
         int anything_pos_size) {
  if (tmp.size() == anything_pos_size) {
    res.push_back(tmp);
    return;
  }
  for(int i = 0; i < fruits.size(); ++i) {
      tmp.push_back(fruits[i]);
      dfs(tmp, res, fruits, anything_pos_size);
      tmp.pop_back();
  }
}

// generate_cands replace possible appearance of "anything" appeard in `code` with all possible
// kinds of fruits tracked in `m` and returns the resulting set of `code` variants.
// Example: `code` has {"orange", "anything", "orange"}; `m` has {"orange", "apple", "mongo"}
// The return are: {"orange", "orange", "orange"}, {"orange", "apple", "orange"}, {"orange", "mongo", "orange"}
vector<vector<string>> generate_cands(vector<string> code, const unordered_map<string,int>& m) {
  vector<int> anything_pos;
  vector<vector<string>> res;
  for(int i = 0; i < code.size(); ++i) {
    if (code[i] == "anything") {
      anything_pos.push_back(i);
    }
  }
  if (anything_pos.size() == 0) {
    res.push_back(code);
    return res;
  }
  vector<string> fruits;
  for(auto&& item: m) {
    fruits.push_back(item.first);
  }
  vector<string> tmp;
  vector<vector<string>> cands;
  dfs(tmp, cands, fruits, anything_pos.size());
  for(auto&& v : cands) {
    for(int i = 0; i < anything_pos.size(); ++i) {
      code[anything_pos[i]] = v[i];
    }
    res.push_back(code);
  }
  return res;
}

// NOTE: the actual problem may be based on the Linked List
int checkWinner (vector<vector<string>> codeList, vector<string> shoppingCart) {
  unordered_map<string, int> m;
  for(auto&& fruit: shoppingCart) {
    m[fruit]++;
  }
  int num_kind_fruit = m.size();
  int matched_index = 0;
  for(auto&& code: codeList) {
    int code_size = code.size();
    int i;
    for(i = 0; i <= shoppingCart.size() - code_size; ++i) {
      auto code_set = generate_cands(code, m);
      vector<string> v(shoppingCart.begin() + i, shoppingCart.begin() + i + code_size);
      for(auto&& cand: code_set) {
        if (v == cand) {
          if (i >= matched_index) {
            // we check `matched_index` as the ordering of appearance of `code` in the `shoppingCart`
            // has to be consistent with ordering of appearance of `code` in `codeList`
            matched_index = i;
            goto endloop;
          } else {
            return 0;
          }
        }        
      }
    }
  endloop:    
    if (i == shoppingCart.size() - code_size + 1) {
      return 0;
    }
  }
  return 1;
}

using ptr2checkWinner = int (*) (vector<vector<string>>, vector<string>);

void test(ptr2checkWinner pfcn, const char* pfcn_name) {
  struct testCase {
    vector<vector<string>> codeList;
    vector<string> shoppingCart;
    int expected;
  };
  vector<testCase> test_cases = {
   {{{"apple", "apple"}, {"orange", "banana", "orange"}},
    {"orange", "apple", "apple", "orange", "banana", "orange"},
    1},
   {{{"orange", "banana", "orange"}, {"apple", "apple"}},
    {"orange", "apple", "apple", "orange", "banana", "orange"},
    0},
   {{{"apple", "apple"}, {"orange", "banana", "orange"}, {"pear", "orange", "grape"}},
    {"orange", "apple", "apple", "orange", "banana", "orange", "pear", "grape"},
    0},
   {{{"apple", "apple"}, {"orange", "anything", "orange"}},
    {"orange", "apple", "apple", "orange", "mango", "orange"},
    1},
   {{{"apple", "apple"}, {"orange", "banana", "orange"}},
    {"orange", "apple", "apple", "orange", "apple", "orange", "banana", "orange"},
    1},
    {{{"anything", "anything"}},
     {"orange", "apple", "grape"},
     1},
  };
  for(auto&& test_case: test_cases) {
    int got = (*pfcn)(test_case.codeList, test_case.shoppingCart);
    if (got != test_case.expected) {
      printf("%s(%s, %s) = %d\n",
             pfcn_name,
             CPPUtility::twoDVectorStr<string>(test_case.codeList).c_str(),
             CPPUtility::oneDVectorStr<string>(test_case.shoppingCart).c_str(),
             got);
      assert(false);
    }
  }
}

int main() {
  ptr2checkWinner pfcn = &checkWinner;
  test(pfcn, FUNC_DEF_NAME(&checkWinner));
}
