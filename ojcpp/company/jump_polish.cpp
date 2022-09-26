//
// Created by rui zhou on 05/05/19.
//

#include <codech/codech_def.h>
#include <stack>
using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int MAX_VALUE = 0xfff;
    //if (S.empty()) return 0;
    stack<int> st;

    for (auto &c:S) {
        if (isdigit(c)) {
            st.push(c-'0');
        } else if (c=='+' || c=='*') {
            if (st.size()>=2) {
                int rhs=st.top();st.pop();
                int lhs=st.top();st.pop();
                switch (c) {
                    case '+':
                        if (lhs+rhs > MAX_VALUE) {
                            return -1;
                        } else {
                            st.push(lhs+rhs);
                        }
                        break;
                    case '*':
                        if (lhs*rhs > MAX_VALUE) {
                            return -1;
                        } else {
                            st.push(lhs*rhs);
                        }
                        break;
                }
            } else {
                return -1;
            }
        }
    }

    if (st.empty()) {
        return -1;
    } else {
        return st.top();
    }
}


DEFINE_CODE_TEST(jump_polish_notation)
{
    {
        string s0="";
        VERIFY_CASE(solution(s0),-1);
    }
    {
        string s0="1+";
        VERIFY_CASE(solution(s0),-1);
    }
    {
        string s0="1+2";
        VERIFY_CASE(solution(s0),-1);
    }
    {
        string s0="123456";
        VERIFY_CASE(solution(s0),6);
    }

    {
        string s0="13+62*7+*";
        VERIFY_CASE(solution(s0),76);
    }
    {
        string s0="11++";
        VERIFY_CASE(solution(s0),-1);
    }
    {
        string s0="9999999999**********";
        VERIFY_CASE(solution(s0),-1);
    }
    {
        string s0="9999****";
        VERIFY_CASE(solution(s0),-1);
    }

}


