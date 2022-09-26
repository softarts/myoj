//
// Created by rui zhou on 05/05/19.
//

#include <codech/codech_def.h>

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> dp(31,0);
    const int COST_1DAY=2,COST_7DAY=7,COST_30DAY=25;

    unordered_set<int> plan(A.begin(),A.end());
    for (int i=1;i<31;i++) {
        if (plan.count(i)==0) {
            dp[i]=dp[i-1];
        } else {
            dp[i]=min({dp[i-1]+COST_1DAY,dp[max(0,i-7)]+COST_7DAY,dp[max(0,i-30)]+COST_30DAY});
        }
    }
    return dp[30];
}


DEFINE_CODE_TEST(jump_minium_ticket_cost)
{
    {
        vector<int> a{};
        VERIFY_CASE(solution(a),0);
    }
    {
        vector<int> a{5};
        VERIFY_CASE(solution(a),2);
    }
    {
        vector<int> a{5,6,7,8,9,10,11};
        VERIFY_CASE(solution(a),7);
    }

    {
        vector<int> a{1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,27,30};
        VERIFY_CASE(solution(a),24);
    }
    {
        vector<int> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
        VERIFY_CASE(solution(a),25);
    }
    {
        vector<int> a{1,2,4,5,7,29,30};
        VERIFY_CASE(solution(a),11);
    }

}