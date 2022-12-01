#include <vector>
#include <map>
using namespace std;

/*
hackerrank 类似, GIC测试题
https://leetcode.com/discuss/interview-question/1028649/snowflake-oa-maximum-order-volume
starttime>=1

这是一种map方式的dp

在一个带起始时间区间内的orders,求何种组合能取得order的最大值
极值问题一般是使用dp(map)，状态转移方程：
以end_time为key的map
dp[end_time]的上一个的volume dp[i-1](形式上), 取与不取下一个order
假如取下一个order,dp[]
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        // 以endtime进行排序
        for (int i=0;i<profit.size();i++) {
            jobs.push_back({endTime[i],startTime[i],profit[i]});
        }

        //建立dp, key为endtime, 目标是dp[endtime]的值最大
        map<int,int> dp{{0,0}};
        sort(jobs.begin(),jobs.end());

        for (auto &job:jobs) {
            // 找到早于等于本starttime的 dp记录,  + 本个job的value
            auto curr = prev(dp.upper_bound(job[1]))->second + job[2];
            // 如果新的value比dp中最迟的key(endtime)还要大
            // 本endtime加到dp中
            if (curr > dp.rbegin()->second) {
                dp[job[0]] = curr;
            }
        }
        return dp.rbegin()->second;
    }
};
