//    A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com",
//    at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain
//    like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//
//    Now, call a "count-paired domain" to be a count (representing the number of visits this domain received),
//    followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
//
//    We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains,
//    (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
//
//    - Example 1:
//    Input:
//    ["9001 discuss.leetcode.com"]
//    Output:
//    ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
//    Explanation:
//    We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
//
//    - Example 2:
//    Input:
//    ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
//    Output:
//    ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
//    Explanation:
//    We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
//
//    - Notes:
//
//    The length of cpdomains will not exceed 100.
//    The length of each domain name will not exceed 100.
//    Each address will have either 1 or 2 "." characters.
//    The input count in any count-paired domain will not exceed 10000.
//    The answer output can be returned in any order.

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<string>
    subdomainVisits( vector<string> &cpdomains )
    {
        vector<string> res;
        unordered_map<string, int> table;
        for ( auto &cpdomain : cpdomains )
        {
            stringstream ss( cpdomain );
            string count_buf;
            int count;
            string buf;
            vector<string> tokens;
            getline( ss, count_buf, ' ' );
            count = stoi( count_buf );
            // C++: how we can split the string by '.'
            while ( getline( ss, buf, '.' ))
            {
                tokens.push_back( buf );
            }
            for ( int i = tokens.size() - 1; i >= 0; i-- )
            {
                // C++: how we can take subvector from a vector
                auto subtokens = vector<string>( tokens.begin() + i, tokens.end());
                string s;
                // C++: how we join the strings with '.'
                for ( auto &token : subtokens )
                {
                    s.append( token );
                    s.append( "." );
                }
                s.pop_back();
                table[s] += count;
            }
        }
        for ( auto &item : table )
        {
            stringstream buf2;
            buf2 << item.second << " " << item.first;
            res.push_back( buf2.str());
        }
        return res;
    }


    // More optimized solution
    vector<string>
    subdomainVisits2( vector<string> &cpdomains )
    {
        unordered_map<string, int> table;
        vector<string> res;

        for ( auto &cpdomain: cpdomains )
        {
            // first split cpdomain into int n and string s
            int i = cpdomain.find( " " );
            int n = stoi( cpdomain.substr( 0, i ));
            string s = cpdomain.substr( i + 1, cpdomain.size() - i - 1 );

            for ( int i = s.size() - 1; i >= 0; i-- )
            {
                // parse s backwards looking for "." and do a+=n to a hashmap with the substring for domain
                if ( s[i] == '.' )
                {
                    table[s.substr( i + 1, s.size() - i - 1 )] += n;
                }
                else if ( i == 0 )
                {
                    // make sure to add the whole domain to hashmap when you hit beginning of line
                    table[s.substr( 0, s.size())] += n;
                }
            }
        }

        for ( auto &item : table )
        {
            res.push_back( to_string( item.second ) + " " + item.first );
        }
        return res;
    }
};

using ptr2subdomainVisits = vector<string>( Solution::* )( vector<string> & );


void
test( ptr2subdomainVisits pfcn )
{
    Solution sol;
    vector<string> input = {"9001 discuss.leetcode.com"};
    auto res = (sol.*pfcn)( input );
    vector<string> ans = {"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};
    int count = 0;
    for ( auto &item: res )
    {
        if ( find( ans.begin(), ans.end(), item ) != ans.end())
        {
            count++;
        }
    }
    assert( count == ans.size());

    input = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    res = (sol.*pfcn)( input );
    ans = {"901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"};
    count = 0;
    for ( auto &item: res )
    {
        if ( find( ans.begin(), ans.end(), item ) != ans.end())
        {
            count++;
        }
    }
    assert( count == ans.size());
}


int
main()
{
    ptr2subdomainVisits pfcn = &Solution::subdomainVisits;
    test( pfcn );
    pfcn = &Solution::subdomainVisits2;
    test( pfcn );
}