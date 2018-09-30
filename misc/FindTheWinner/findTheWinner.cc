// Visa OA 2018

#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    string findTheWinner(string s, vector<int> andrea, vector<int> maria)
    {
        int andrea_sum = 0;
        int maria_sum = 0;
        for(int i = 0; i < andrea.size(); ++i)
        {
            if (s == "Even" && i % 2 == 0)
            {
                andrea_sum += andrea[i];
                maria_sum += maria[i];
            }
            else if (s == "Odd" && i % 2 == 1)
            {
                andrea_sum += andrea[i];
                maria_sum += maria[i];
            }
        }
        if (andrea_sum > maria_sum)
        {
            return "Andrea";
        }
        else if (andrea_sum < maria_sum)
        {
            return "Maria";
        }
        else
        {
            return "Tie";
        }
    }
};

using ptr2findTheWinner = string (Solution::*)(string, vector<int>, vector<int>);

void test(ptr2findTheWinner pfcn)
{
    Solution sol;
    vector<int> andrea = {1,2,3};
    vector<int> maria = {2,1,3};
    assert((sol.*pfcn)("Even", andrea, maria) == "Maria");

    andrea = {4,5,7};
    maria = {3,5,6};
    assert((sol.*pfcn)("Even", andrea, maria) == "Andrea");
}

int main()
{
    ptr2findTheWinner pfcn = &Solution::findTheWinner;
    test(pfcn);
}