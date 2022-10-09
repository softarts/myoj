// Forward declaration of the knows API.
// lc277
bool knows(int a, int b);
/*
假设你和 n 个人在一个聚会中(标记为 0 到 n - 1)，其中可能存在一个名人。名人的定义是所有其他 n - 1 人都认识他/她，但他/她不知道任何一个。
现在你想要找出这个名人是谁或者验证这个名人不存在。你唯一可以做的事情就是提出如下问题：“你好，A，你认识B吗？” 
来获取A是否认识B。您需要通过询问尽可能少的问题(以渐近的意义)来找出名人是谁(或验证其不存在)。
你得到一个辅助函数 bool knows(a，b)，它会告诉你A是否知道B.实现一个函数 int findCelebrity(n)，
你的函数应该使 knows 的调用次数最少。

输入：
2 // 接下来n*(n-1)行
0 knows 1
1 does not know 0
输出： 1
解释：
所有人都认识1，而且1不认识其他人。

这题不太适合面试,如何取得最小的knows调用次数？
暴力法 O(N^2)

*/
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        int ans=0;
        vector<vector<int>> m(n,vector<int>(n,-1));
        // 可能得到ans并不是名人，因为前面的一些数字并未验证该人，跳过了太多步骤
        for (int i=0;i<n;i++) {
            bool k = knows(i,ans);
            m[i][ans]=int(k);
            if (!k) {
                cout<<"ans="<<ans<<endl;
                ans=i;
            }
        }
        

        // 确认候选人是否是名人
        for(int i=0;i<n;i++){
            if(i==ans) continue;
            bool resKnowI=m[ans][i]>=0?m[ans][i]:knows(ans,i);

            bool iKnowRes=m[i][ans]>=0?m[i][ans]:knows(i,ans);
            // 如果候选人认识某个人，或者某人不认识候选人，候选人不是名人
            if(resKnowI || !iKnowRes) return -1;
        }
        return ans;

    }
        
};