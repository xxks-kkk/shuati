//http://www.1point3acres.com/bbs/thread-443848-1-1.html
#include <string>
#include <vector>
#include <cassert>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string>
    fetchItemsToDisplay(vector<vector<string>> &items, int sortParameter, int sortOrder, int x, int y)
    {
        vector<string> res;
        typedef function<bool(vector<string>, vector<string>)> Comparator;
        Comparator comp = [sortOrder, sortParameter](vector<string> item1, vector<string>item2) -> bool {
            if (sortOrder == 0)
            {
                // ascending order (min heap)
                if (sortParameter == 0)
                {
                    return item1[0] > item2[0];
                }
                else if (sortParameter == 1)
                {
                    return stoi(item1[1]) > stoi(item2[1]);
                }
                else if (sortParameter == 2)
                {
                    return stoi(item1[2]) > stoi(item2[2]);
                }
            }
            else if (sortOrder == 1)
            {
                // descending order (max heap)
                if (sortParameter == 0)
                {
                    return item1[0] < item2[0];
                }
                else if (sortParameter == 1)
                {
                    return stoi(item1[0]) > stoi(item2[0]);
                }
                else if (sortParameter == 2)
                {
                    return stoi(item1[0]) > stoi(item2[0]);
                }
            }
        };
        priority_queue<vector<string>, vector<vector<string>>, Comparator> pq(comp);
        for(auto& item : items)
        {
            pq.push(item);
        }
        int numPage = -1;
        while(!pq.empty())
        {
            auto front = pq.top();
//            for(auto& i : front)
//            {
//                cout << i << "\t";
//            }
//            cout << endl;
            pq.pop();
            numPage++;
            if (numPage/x == y)
            {
                res.push_back(front[0]);
            }
        }
        return res;
    }
};

using ptr2fetchItemsToDisplay = vector<string> (Solution::*)(vector<vector<string>> &, int, int, int, int);

void
test(ptr2fetchItemsToDisplay pfcn)
{
    Solution sol;
    int n = 3;
    vector<vector<string>> items = {
        {"item1", "10", "15"},
        {"item2", "3", "4"},
        {"item3", "17", "8"}
    };
    int sortParameter = 1; // which column we want to sort on
    int sortOrder = 0; // 0: ascending; 1: descending
    int x = 2;
    int y = 1;
    vector<string> ans = {"item3"};
    assert((sol.*pfcn)(items, sortParameter, sortOrder , x, y) == ans);
}

int
main()
{
    ptr2fetchItemsToDisplay pfcn = &Solution::fetchItemsToDisplay;
    test(pfcn);
}