//
// Created by rui zhou on 2019-11-02.
//

/*
 反转字符串

 lc557

 */


#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;



namespace {
    class Solution {
    public:
        string reverseWords(string s) {
            string ans;
            stack<string> st;
            stringstream ss(s);
            string tmp;

            while (getline(ss,tmp,' ')) {
                st.push(tmp);
            }

            while (!st.empty()) {
                ans+=st.top();
                st.pop();
                if (!st.empty())
                    ans+=' ';
            }
            return ans;
        }
    };
}


DEFINE_CODE_TEST(042_reverse_str)
{
    Solution obj;
    {
        VERIFY_CASE(obj.reverseWords("I am a student."),"student. a am I");

    }

}


