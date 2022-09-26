//
// Created by rui zhou on 10/05/19.
//

// n个骰子，所有朝上一面的点数之和为s，求s的各种取值的概率
// lc1155

#include <codech/codech_def.h>
#include <cmath>
using namespace std;

namespace {
    // backtracking
    class Solution0 {
    public:
        void probability(int n) {
            vector<int> count(6*n+1,0);
            int maxSum=n*6;
            helper(0,n,0,count);

            int total = pow(6,n);
            for (int i=n;i<=maxSum;i++) {
                double ratio = (double)count[i-n+1]/total;
                cout << i << ":" << ratio << endl;
            }
        }

        void helper(int start, int n, int sum, vector<int> &count) {
            if (start==n) {
                count[sum]+=1;return;
            }
            for (int i=start;i<n;i++) {
                for (int j=1;j<=6;j++) {
                    helper(i+1,n,sum+j,count);
                }
            }
        }
    };

    // 动态规划来解决概率问题，把问题分解为n骰子和为s的概率，等于n-1个骰子和为y的概率 乘以 1个骰子和为z的概率，其中s=y+z
    // dp[i][j], i为骰子数,j为和

    // dp[i]定义为第i次出现的所有和的可能及其对应的概率，递推公式dp[i][x] = dp[i-1][y] * dp[1][z]，且x = y + z
    // dp[i][2] = dp[i-1][1]*dp[1][1]的概率，然而 dp[i][1]怎么办？必须从dp[i]开始
    class Solution {
    public:
        vector<pair<int, double>> probability(int n) {
            vector<unordered_map<int,double>> dp(n+1);
            dp[1]={{1,1/6.0},{2,1/6.0},{3,1/6.0},{4,1/6.0},{5,1/6.0},{6,1/6.0}};
            for (int i=2;i<=n;i++) {
                for (int j=i;j<=n;j++) {
                    for (int k=1;k<=6&&j-k>0&&j-k>=(i-1);k++) {
                        dp[i][j] += dp[i-1][j-k]*dp[1][k];
                    }
                }
            }
            vector<pair<int, double>> res;
//            for (auto a : dp[n]) {
//                res.push_back({a.first, a.second});
//            }
            for (int i=n*1;i<=6*n;i++) {
                res.push_back({i,dp[n][i]});
            }
            return res;
        }
    };
}

void PRINT_VMAP(const vector<pair<int, double>> &v) {
    for (auto &it:v) {
        cout << it.first << " -> " << it.second << endl;
    }
}

DEFINE_CODE_TEST(hht_043_diceprob)
{
    Solution obj;
    PRINT_VMAP(obj.probability(2));
    //PRINT_VMAP(obj.probability(1));
}