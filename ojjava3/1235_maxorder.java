/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104

it is greedy or dp programming, need to find max voume
find max at dp[endtime]
*/

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        // init jobs array, sort by endtime
        int n = profit.length;
        int [][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i] = new int[]{endTime[i], startTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a,b)-> a[0] - b[0]);

        // use treemap to store DP information,
        // target, find the latest dp max value;
        // dp key is endtime, value is profit at that moment
        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0, 0); // base

        // travelsal the jobs
        Arrays.stream(jobs).forEach(job -> {
            int currEndTime = job[0];
            int currStartTime = job[1];
            int currProfit  = job[2];

            // find end earlier than current starttime            
            int prevProfit = dp.floorEntry(currStartTime).getValue();
            int newCurrProfit = prevProfit + currProfit;

            //compare with the current latest dp profit
            if (newCurrProfit > dp.lastEntry().getValue()) {
                dp.put(currEndTime, newCurrProfit);
            }
        });
        return dp.lastEntry().getValue();
    }
}


// class Solution {
//     public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
//         int n = profit.length;
//         // 1. 组装 jobs: [endTime, startTime, profit]
//         int[][] jobs = new int[n][3];
//         for (int i = 0; i < n; i++) {
//             jobs[i] = new int[]{endTime[i], startTime[i], profit[i]};
//         }

//         // 2. 按照 endTime 进行升序排序 (对应 C++ 的 sort)
//         Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));

//         // 3. 建立 dp，key 为 endTime，value 为当前最大收益
//         // 初始化映射 {0: 0}
//         TreeMap<Integer, Integer> dp = new TreeMap<>();
//         dp.put(0, 0);

//         for (int[] job : jobs) {
//             int curEndTime = job[0];
//             int curStartTime = job[1];
//             int curProfit = job[2];

//             // 4. 找到早于等于本 starttime 的 dp 记录 (完美替代 C++ 的 prev(dp.upper_bound))
//             // floorEntry(key) 返回小于等于 key 的最大 Entry
//             int prevProfit = dp.floorEntry(curStartTime).getValue();
//             int curr = prevProfit + curProfit;

//             // 5. 如果新的 value 比 dp 中最迟的 value 还要大 (对应 C++ 的 dp.rbegin()->second)
//             // lastEntry() 可以直接拿到 TreeMap 中 key 最大的那条记录
//             if (curr > dp.lastEntry().getValue()) {
//                 dp.put(curEndTime, curr);
//             }
//         }

//         // 6. 返回最后一个（最大的）完成时间对应的最高收益
//         return dp.lastEntry().getValue();
//     }
// }

// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         vector<vector<int>> jobs;
//         // 以endtime进行排序
//         for (int i=0;i<profit.size();i++) {
//             jobs.push_back({endTime[i],startTime[i],profit[i]});
//         }

//         //建立dp, key为endtime, 目标是dp[endtime]的值最大
//         map<int,int> dp{{0,0}};
//         sort(jobs.begin(),jobs.end());

//         for (auto &job:jobs) {
//             // 找到早于等于本starttime的 dp记录,  + 本个job的value
//             auto curr = prev(dp.upper_bound(job[1]))->second + job[2];
//             // 如果新的value比dp中最迟的key(endtime)还要大
//             // 本endtime加到dp中
//             if (curr > dp.rbegin()->second) {
//                 dp[job[0]] = curr;
//             }
//         }
//         return dp.rbegin()->second;
//     }
// };