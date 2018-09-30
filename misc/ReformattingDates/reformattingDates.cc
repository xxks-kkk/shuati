#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<string> reformatDate(vector<string> dates)
    {
        unordered_map<string, string> Day, Month;
        Day["1st"] = "01";
        Day["2nd"] = "02";
        Day["3rd"] = "03";
        Day["4th"] = "04";
        Day["5th"] = "05";
        Day["6th"] = "06";
        Day["7th"] = "07";
        Day["8th"] = "08";
        Day["9th"] = "09";
        Day["10th"] = "10";
        Day["11th"] = "11";
        Day["12th"] = "12";
        Day["13th"] = "13";
        Day["14th"] = "14";
        Day["15th"] = "15";
        Day["16th"] = "16";
        Day["17th"] = "17";
        Day["18th"] = "18";
        Day["19th"] = "19";
        Day["20th"] = "20";
        Day["21st"] = "21";
        Day["22nd"] = "22";
        Day["23rd"] = "23";
        Day["24th"] = "24";
        Day["25th"] = "25";
        Day["26th"] = "26";
        Day["27th"] = "27";
        Day["28th"] = "28";
        Day["29th"] = "29";
        Day["30th"] = "30";
        Day["31st"] = "31";

        Month["Jan"] = "01";
        Month["Feb"] = "02";
        Month["Mar"] = "03";
        Month["Apr"] = "04";
        Month["May"] = "05";
        Month["Jun"] = "06";
        Month["Jul"] = "07";
        Month["Aug"] = "08";
        Month["Sep"] = "09";
        Month["Oct"] = "10";
        Month["Nov"] = "11";
        Month["Dec"] = "12";

        vector<string> res;
        for(auto& date: dates)
        {
            stringstream ss(date);
            string day, month, year;
            getline(ss, day, ' ');
            getline(ss, month, ' ');
            getline(ss, year, ' ');
            res.push_back(year + "-" + Month[month] + "-" + Day[day]);
        }
        return res;
    }
};

using ptr2reformatDate = vector<string> (Solution::*)(vector<string>);

void test(ptr2reformatDate pfcn)
{
    Solution sol;
    vector<string> dates = {
        "20th Oct 2052",
        "6th Jun 1933",
        "26th May 1960",
        "20th Sep 1958",
        "16th Mar 2068",
        "25th May 1912",
        "16th Dec 2018",
        "26th Dec 2061",
        "4th Nov 2030",
        "28th Jul 1963"
    };
    vector<string> ans = {
        "2052-10-20",
        "1933-06-06",
        "1960-05-26",
        "1958-09-20",
        "2068-03-16",
        "1912-05-25",
        "2018-12-16",
        "2061-12-26",
        "2030-11-04",
        "1963-07-28"
    };
    assert((sol.*pfcn)(dates) == ans);
}

int main()
{
    ptr2reformatDate pfcn = &Solution::reformatDate;
    test(pfcn);
}