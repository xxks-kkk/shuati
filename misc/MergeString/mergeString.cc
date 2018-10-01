// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=446249&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26sortid%3D311
#include <string>
#include <cassert>

using namespace std;

class Solution{
public:
    string mergeStrings(string a, string b)
    {
        int i = 0;
        int j = 0;
        string res;
        while(i < a.length() || j < b.length())
        {
            char c, d;
            if(i != a.length())
            {
                c = a[i];
                res += c;
                i++;
            }
            if(j != b.length())
            {
                d = b[j];
                res += d;
                j++;
            }
        }
        return res;
    }
};

using ptr2mergeStrings = string (Solution::*)(string, string);

void test(ptr2mergeStrings pfcn)
{
    Solution sol;
    string a = "abc";
    string b = "stuvwx";
    assert((sol.*pfcn)(a,b) == "asbtcuvwx");

    a = "abc";
    b = "def";
    assert((sol.*pfcn)(a,b) == "adbecf");

    a = "ab";
    b = "zsd";
    assert((sol.*pfcn)(a,b) == "azbsd");
}

int main()
{
    ptr2mergeStrings pfcn = &Solution::mergeStrings;
    test(pfcn);
}