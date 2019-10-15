// Amazon OA (10/11/19)

#include "cpputility.h"

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string str, string delim) {
  vector<string> tokens;
  int prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

vector<string> prioritizedOrders(int numOrders, vector<string> orderList)
{
  vector<string> non_prime;
  vector<string> prime;
  for(auto&& order: orderList) {
    auto tokens = split(order, " ");
    if (tokens[1].find_first_not_of("0123456789") == string::npos) {
      non_prime.push_back(order);
    } else {
      prime.push_back(order);
    }
  }
  auto comp = [](string& order1, string& order2) {
                // here, we implement the comparator to compare two prime orders
                auto order1_tokens = split(order1, " ");
                auto order2_tokens = split(order2, " ");
                string order1_meta = "";
                string order2_meta = "";
                for(int i = 1; i < order1_tokens.size(); ++i) {
                  order1_meta += (order1_tokens[i] + " ");
                }
                for(int i = 1; i < order2_tokens.size(); ++i) {
                  order2_meta += (order2_tokens[i] + " ");
                }
                if (order1_meta < order2_meta) return true;
                else if (order1_meta > order2_meta) return false;
                else {
                  return order1_tokens[0] < order2_tokens[0];
                }
              };
  sort(prime.begin(), prime.end(), comp);
  std::move(non_prime.begin(), non_prime.end(), std::back_inserter(prime));
  return prime;
}

using ptr2prioritizedOrders = vector<string> (*) (int, vector<string>);

void test(ptr2prioritizedOrders pfcn, const char* pfcn_name) {
  struct testCase {
    int numOrders;
    vector<string> orderList;
    vector<string> expected;
  };
  vector<testCase> test_cases = {
    {6, {"zld 93 12", "fp kindle book", "10a echo show", "17g 12 25 6", "abl kindle book", "125 echo dot second generation"},
     {"125 echo dot second generation", "10a echo show", "abl kindle book", "fp kindle book", "zld 93 12", "17g 12 25 6"}},
    {4, {"mi2 jog mid pet", "wz3 34 54 398", "a1 alps cow bar", "x4 45 21 7"},
     {"a1 alps cow bar", "mi2 jog mid pet", "wz3 34 54 398",  "x4 45 21 7"}},
    {6, {"t2 13 121 98", "r1 box ape bit", "b4 xi me nu", "br8 eat nim did", "w1 has uni gry", "f3 52 54 31"},
     {"r1 box ape bit", "br8 eat nim did", "w1 has uni gry", "b4 xi me nu", "t2 13 121 98",  "f3 52 54 31"}},
  };
  for(auto&& test_case: test_cases) {
    auto got = (*pfcn)(test_case.numOrders, test_case.orderList);
    if (got != test_case.expected) {
      printf("%s(%d, %s) = %s\n",
             pfcn_name,
             test_case.numOrders,
             CPPUtility::oneDVectorStr<string>(test_case.orderList).c_str(),
             CPPUtility::oneDVectorStr<string>(got).c_str());
      assert(false);
    }
  }  
}

int main() {
  ptr2prioritizedOrders pfcn = &prioritizedOrders;
  test(pfcn, FUNC_DEF_NAME(&prioritizedOrders));
}
