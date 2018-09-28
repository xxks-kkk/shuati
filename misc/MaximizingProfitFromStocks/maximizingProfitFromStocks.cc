#include <cassert>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void maxProfit(string inputFile){
        ifstream input(inputFile);
        string numCases;
        getline(input, numCases);
        while(!input.eof())
        {
            string N;
            string testcase;
            getline(input, N);
            if (N.length() != 1)
            {
                testcase = N;
            }
            else
            {
                getline( input, testcase );
            }
            auto tokens = split(testcase);
            cout << findProfit(tokens) << endl;
        }
    }

private:
    int findProfit(vector<int> tokens)
    {
        // similar to the trap water problem
        // http://www.1point3acres.com/bbs/thread-439109-1-1.html
        int profit = 0;
        int n = tokens.size();
        vector<int> max_right(n);
        max_right[n-1] = tokens[n-1];
        for(int i = n-2; i >= 0; --i)
        {
            max_right[i] = max(max_right[i+1], tokens[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            profit += max_right[i] - tokens[i];
        }
        return profit;
    }

    vector<int> split(string s)
    {
        string token;
        vector<int> tokens;
        size_t pos = 0;
        while((pos = s.find(' ') != string::npos))
        {
            token = s.substr(0, pos);
            tokens.push_back(stoi(token));
            s.erase(0, pos + 1);
        }
        tokens.push_back(stoi(s)); // last left over
        return tokens;
    }
};

void test()
{
    string inputFile = "/Users/zeyuan/Documents/projects/shuati/misc/MaximizingProfitFromStocks/input.txt";
    Solution sol;
    sol.maxProfit(inputFile);
}

int main()
{
    test();
}