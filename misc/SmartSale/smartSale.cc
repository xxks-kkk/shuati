#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cassert>

using namespace std;

class Solution{
public:
    int deleteProducts(vector<int> ids, int m)
    {
        // C++: how we sort the map by value (https://thispointer.com/how-to-sort-a-map-by-value-in-c/)
        typedef function<bool(pair<int,int>, pair<int,int>)> Comparator;
        Comparator comp = [](pair<int,int> item1, pair<int,int> item2) -> bool{
            return item1.second < item2.second;
        };
        map<int,int> table;
        for(auto& id : ids)
        {
            table[id]++;
        }
        int numKinds = table.size();
        int numKindsRemoved = 0;
        set<pair<int,int>, Comparator> tableset(make_move_iterator(table.begin()), make_move_iterator(table.end()), comp);
        for(auto& item: tableset)
        {
            if (m - item.second >= 0)
            {
                tableset.erase(item);
                m -= item.second;
                numKindsRemoved += 1;
            }
            else
            {
                break;
            }
        }
        return numKinds - numKindsRemoved;
    }
};

using ptr2deleteProducts = int (Solution::*)(vector<int>, int);

void test(ptr2deleteProducts pfcn)
{
    Solution sol;
    int m = 2;
    vector<int> ids = {1,1,2,1,3,2};
    assert((sol.*pfcn)(ids, m) == 2);
}

int main()
{
    ptr2deleteProducts pfcn = &Solution::deleteProducts;
    test(pfcn);
}