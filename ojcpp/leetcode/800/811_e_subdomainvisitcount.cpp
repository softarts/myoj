//
// Created by rui zhou on 01/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-78/problems/subdomain-visit-count/
 * A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input:
["9001 discuss.leetcode.com"]
Output:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation:
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation:
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:

The length of cpdomains will not exceed 100.
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.

问题，就是将域名分解,计算各有多少访问次数
 */


#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto &line: cpdomains) {
            auto first_token = line.substr(0, line.find(' '));
            auto domain = line.substr(line.find(' '));
            int count = stoi(first_token);
            m[domain] = count;
            size_t begin = 0;
            while (true) {
                size_t pos = line.find('.',begin);
                if (pos==string::npos)
                    break;
                auto subdomain = line.substr(pos+1);
                m[subdomain] += count;
                begin = pos+1;
            }
        }
        vector<string> ret;
        for (auto &cpi:m) {
            string line = to_string(cpi.second) + " " +cpi.first;
            ret.push_back(line);
            cout << line << endl;
        }
        return ret;
    }
};


DEFINE_CODE_TEST(811_subdomainvisitcount)
{
    Solution obj;
    {
        vector<string> cps{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
        obj.subdomainVisits(cps);
    }
}
