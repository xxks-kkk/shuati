#include "cpputility.h"

using namespace std;

// NOTE: the actual problem may be based on the Linked List
int checkWinner (vector<vector<string>> codeList, vector<string> shoppingCart) {
  int matched_index = 0;
  for(auto&& code: codeList) {
    int code_size = code.size();
    int i;
    for(i = 0; i <= shoppingCart.size() - code_size; ++i) {
      vector<string> v(shoppingCart.begin() + i, shoppingCart.begin() + i + code_size);
      if (v == code) {
        if (i >= matched_index) {
          matched_index = i;
          break;
        } else {
          return 0;
        }
      }
    }
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
