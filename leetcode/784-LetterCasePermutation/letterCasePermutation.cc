//    Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
//    Return a list of all possible strings we could create.
//
//    Examples:
//    Input: S = "a1b2"
//    Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//    Input: S = "3z4"
//    Output: ["3z4", "3Z4"]
//
//    Input: S = "12345"
//    Output: ["12345"]
//
//    Note:
//
//    S will be a string with length between 1 and 12.
//    S will consist only of letters or digits.

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> sol;
        vector<bool> a;
        vector<int> pos;
        for(int i = 0; i < S.length(); ++i) {
            if (isalpha(S[i])) {
                pos.emplace_back(i);
            }
        }
        backtrack(sol, a, S, pos);
        return sol;
    }
private:
    void backtrack(vector<string>& sol, vector<bool> a, string S, const vector<int>& pos) {
        if (a.size() == pos.size()){
            string tmp = S;
            for(int i = 0; i < a.size(); ++i){
                if (a[i]) tmp[pos[i]] = toupper(tmp[pos[i]]);
                else tmp[pos[i]] = tolower(tmp[pos[i]]);
            }
            sol.emplace_back(tmp);
        } else {
            vector<bool> cand = {true, false};
            for(auto&& item: cand) {
                a.push_back(item);
                backtrack(sol, a, S, pos);
                a.pop_back();
            }
        }
    }
};

using ptr2letterCasePermutation = vector<string> (Solution::*)(string);

void test(ptr2letterCasePermutation pfcn) {
    Solution sol;
    string S;
    vector<string> res;
    vector<string> ans;
    unordered_set<string> res_s;
    unordered_set<string> ans_s;

    S = "a1b2";
    res = (sol.*pfcn)(S);
    ans = {"a1b2", "a1B2", "A1b2", "A1B2"};
    res_s = unordered_set<string>(res.begin(), res.end());
    ans_s = unordered_set<string>(ans.begin(), ans.end());
    assert(res_s == ans_s);

    S = "3z4";
    res = (sol.*pfcn)(S);
    ans = {"3z4", "3Z4"};
    res_s = unordered_set<string>(res.begin(), res.end());
    ans_s = unordered_set<string>(ans.begin(), ans.end());
    assert(res_s == ans_s);

    S = "12345";
    res = (sol.*pfcn)(S);
    ans = {"12345"};
    assert(res == ans);

    S = "C";
    res = (sol.*pfcn)(S);
    ans = {"c", "C"};
    res_s = unordered_set<string>(res.begin(), res.end());
    ans_s = unordered_set<string>(ans.begin(), ans.end());
    assert(res_s == ans_s);
}

int main() {
    ptr2letterCasePermutation pfcn = &Solution::letterCasePermutation;
    test(pfcn);
}