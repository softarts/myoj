#include <codech/codech_def.h>

using namespace std;

//Input: stones = [0,1,3,5,6,8,12,17]
//Output: true
// 这种求极值的一般是dp

namespace {
    class Solution {
    public:
        unordered_map<int,bool> dp;
        // 这个是递归的做法,TLE
        bool canCross(vector<int>& stones) {
            return helper(stones,0,0);
        }

        bool helper0(vector<int>& stones, int pos,int k){
            for (int i=pos+1;i<stones.size();i++) {
                int gap = stones[i]-stones[pos];
                if (gap<k-1) continue;
                if (gap>k+1) return false;
                if (helper0(stones,i,gap)) return true;
            }
            return pos==stones.size()-1;
        }

        //使用递归，但是使用hashmap来做剪枝降低运算量,dp的做法有点复杂，看不懂
        //这个backtrace的循环比较容易理解，当gap太大的时候，返回错误
        //当gap太小的时候可以测试下一个元素，正好落在这个范围的时候可以递归
        //注意第一个k=0,因此k的范围是-1,1
        bool helper(vector<int>& stones, int pos,int k){
            int key = pos|k<<11;
            if (dp.count(key)>0) return dp[key];
            for (int i=pos+1;i<stones.size();i++) {
                int gap = stones[i]-stones[pos];
                if (gap<k-1) continue;
                if (gap>k+1) {dp[key]=false;return false;}
                if (helper(stones,i,gap)) {dp[key]=true;return true;};
            }
            dp[key]=(pos==stones.size()-1);            
            return dp[key];
        }
    };
}

DEFINE_CODE_TEST(403_cancross)
{
    Solution obj;
    {
        vector<int> nums{0,1,2,3,4,8,9,11};
        VERIFY_CASE(obj.canCross(nums),true);
    }

}
