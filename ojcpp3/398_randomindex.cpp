#include <vector>
#include <unordered_map>
using namespace std;
/*
可以使用hashtable
也可以采用蓄水池采样, 理论上这个是正解
*/
class Solution {
public:
    // TLE???!!!
    // vector<int> arr_;
    // Solution(vector<int>& nums)
    // :arr_(nums) {
     
    // }
    
    // // 模版
    // int pick(int target) {
    //     int ans=INT_MAX;
    //     int cnt = 1;
    //     for (int i=0;i<arr_.size();i++) {
    //         if (arr_[i]!=target) continue;
    //         if (rand()%cnt==0) {
    //             ans = i;
    //         }
    //         cnt++;
    //     }
    //     return ans;
    // }

    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        //srand((unsigned)time(NULL));
        int index = rand() % m[target].size();
        return m[target][index];
    }
        
    private:
        unordered_map<int, vector<int>>m;
};




/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */