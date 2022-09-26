//
// Created by rui zhou on 08/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-79/problems/largest-sum-of-averages/
 *We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
 9 1 2 3 9

 dp state,

 */

/*
 * class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k) {
        int n = a.size();
        double mem[n][k + 1];
        for (int i = 0; i < n; ++i) for (int j = 0; j <= k; ++j) mem[i][j] = -1.0;
        mem[0][1] = a[0] / 1.0;
        for (int i = 1; i < n; ++i) {
            double s = a[i];
            for (int j = i; j-- > 0; ) {
                for (int u = 0; u < k; ++u) if (mem[j][u] > -0.1) {
                    mem[i][u + 1] = max(mem[i][u + 1], mem[j][u] + s / (i - j));
                }
                s += a[j];
            }
            mem[i][1] = max(mem[i][1], s / (i + 1));
        }
        double ret = 0.0;
        for (int i = 1; i <= k; ++i) ret = max(ret, mem[n - 1][i]);
        return ret;
    }
};
 */
#include <codech/codech_def.h>
#include <numeric>

using namespace std;
namespace {
    class Solution {
    public:
        //TLE, recursive
        double largestSumOfAverages(vector<int> &A, int K) {
            double maxsum = 0.0, prev = 0.0;
            if (K > A.size())
                return 0.0;
            return next(A, K, 0, prev, maxsum);
        }

        double next(vector<int> &nums, int k, int start, double &prev, double &maxsum) {
            int remain = nums.size() - start;
            if (k == 1) {
                return prev + accumulate(nums.begin() + start, nums.end(), 0.0) / (remain);
            }
            double sum;
            for (int i = 0; i < remain - k + 1; i++) {
                sum = prev + accumulate(nums.begin() + start, nums.begin() + start + i + 1, 0.0) / (i + 1);
                maxsum = max(maxsum, next(nums, k - 1, start + i + 1, sum, maxsum));
            }
            return maxsum;
        }
    };

    //DP

    class Solution1 {
    public:
        double largestSumOfAverages(vector<int> &A, int K) {
            if (A.empty())
                return 0;
            size_t n =A.size();
            vector<double> dp(n,0);
            double s = 0;
            //[9,1 2,3,9]->dp[0] 分n group的情况,dp[1]=n-1 group,dp[n-1]是1个group， 注意每个group的avg都是指i~n-1之间的平均数
            for (int i=n-1;i>=0;i--) {
                s+=A[i];
                dp[i]=s/(n-i);
            }
//            dp[i] means the maximum answer of current k in sub array[i....n-1]
//            we iterete k from 1 to K
            for (int m=1;m<K;m++) {  // 1~k
                for (int i=0;i<n-m;i++) {
                    double ksum = 0;
                    for (int j=i;j<n-m;j++) {
                        ksum+=A[j];
                        // 状态转移方程为dp[i] 为
                        double g = dp[j+1]+1.0*ksum/(j+1-i);
                        dp[i] = max(dp[i], g);
                    }
                }
            }
            return dp[0];
        }
    };

    //http://www.cnblogs.com/grandyang/p/9504413.html
    // 这个比较明白
    //第一轮，k=0，不分组，dp[i][0]记下 i-n不分组的最大avg
    //然后再来k=1,2，即k的分组情况依赖于k-1和avg（i~j-1),取得每个位置的k分组所能取得的最大值,放在dp[i][k]处，自然
    // dp[0][k]就是最终要找得值
    //上面用一维数组的情况类似，即不要记多个k了，直接一维数组保存上次结果
    class Solution3 {
    public:
        double largestSumOfAverages(vector<int>& A, int K) {
            int n = A.size();
            vector<double> sums(n + 1);
            vector<vector<double>> dp(n, vector<double>(K));
            for (int i = 0; i < n; ++i) {
                sums[i + 1] = sums[i] + A[i];
            }
            for (int i = 0; i < n; ++i) {
                dp[i][0] = (sums[n] - sums[i]) / (n - i);
            }
            for (int k = 1; k < K; ++k) {
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        dp[i][k] = max(dp[i][k], (sums[j] - sums[i]) / (j - i) + dp[j][k - 1]);
                    }
                }
            }
            return dp[0][K - 1];
        }
    };


//    dp[i] means the maximum answer of current k in sub array[i....n-1]
//    we iterete k from 1 to K
    class Solution2 {
    public:
        double largestSumOfAverages(vector<int>& A, int K) {
            int n  = A.size();
            vector<double> dp(n,0);
            double acc = 0;
            for(int i=n-1;i>=0;i--){
                acc+=A[i];
                dp[i]=acc/(n-i);
            }
            //最后的形态 dp[0]=12.75,dp[1]=11,a[0]=9,所以9+11大于12.75,取20
            //
            for(int k=0;k<K-1;k++){
                for(int i=0;i<n;i++){
                    double acc = 0;
                    for(int j=i;j<n-1;j++){
                        acc+=A[j];
                        dp[i]=max(dp[i],acc/(j-i+1)+dp[j+1]);
                    }
                }
            }

            return dp[0];
        }
    };

}


    //wow ...see explanation in doc
    double largestSumOfAverages2(vector<int>& A, int K) {
        if(A.empty()) return 0.0;

        int n = A.size();
        vector<double> dp(n, 0);
        double sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += A[i];
            dp[i] = sum / (n-i);
        }
        double ans = dp[0];
        for(int k=1;k<K;k++){
            //vector<double> next(n, INT_MIN);
            for(int i=0;i<n-k;i++){
                double s2 = A[i];
                dp[i] = s2 + dp[i+1];
                for(int j=i+1;j<n-k;j++){
                    s2 += A[j];
                    dp[i] = max(dp[i], 1.0 * s2/(j-i+1) + dp[j+1]);
                }
            }
            ans = max(ans, dp[0]);
        }

        return ans;
    }

    double largestSumOfAverages1(vector<int>& a, int k) {
        int n = a.size();
        //double mem[n][k + 1]; // not working in vc++
        double **mem =(double**)malloc(sizeof(double)*n*(k+1));
        for (int i = 0; i < n; ++i) for (int j = 0; j <= k; ++j) mem[i][j] = -1.0;
        mem[0][1] = a[0] / 1.0;
        for (int i = 1; i < n; ++i) {
            double s = a[i];
            for (int j = i; j-- > 0; ) {
                for (int u = 0; u < k; ++u) {
                    double prev = mem[j][u];
                    double newdp = mem[i][u+1];
                    if (mem[j][u] > -0.1) {
                        mem[i][u + 1] = max(mem[i][u + 1], mem[j][u] + s / (i - j));
                    }
                    double *pm = mem[i];
                }
                s += a[j];
            }
            mem[i][1] = max(mem[i][1], s / (i + 1));
        }
        double ret = 0.0;
        for (int i = 1; i <= k; ++i) ret = max(ret, mem[n - 1][i]);
        return ret;
    }



DEFINE_CODE_TEST(813_largest_sum_of_averages)
{
    Solution2 obj;
    {
        vector<int> nums{9,1,2,3,9};
        VERIFY_CASE(obj.largestSumOfAverages(nums, 3),20);
    }
    {
        vector<int> nums{4663,3020,7789,1627,9668,1356,4207,1133,8765,4649,205,6455,8864,3554,3916,5925,3995,4540,3487,5444,8259,8802,6777,7306,989,4958,2921,8155,4922,2469,6923,776,9777,1796,708,786,3158,7369,8715,2136,2510,3739,6411,7996,6211,8282,4805,236,1489,7698};
        COMP_TIMER(obj.largestSumOfAverages(nums, 27),obj.largestSumOfAverages(nums, 27));
    }

    {
        vector<int> nums{9,1,2,3,9};
        VERIFY_CASE(obj.largestSumOfAverages(nums, 5),24);
    }
}