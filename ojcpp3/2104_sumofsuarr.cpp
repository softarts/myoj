#include <vector>
#include <climits>
#include <deque>
#include <functional>
using namespace std;

// brute force
class Solution0 {
public:
    long long subArrayRanges(vector<int>& nums) {
        long ans=0;
        for (int i=0;i<nums.size();i++) {
            int minv=nums[i];
            int maxv=nums[i];
            for (int j=i+1;j<nums.size();j++) {
                minv=min(minv,nums[j]);
                maxv=max(maxv,nums[j]);
                ans+=(maxv-minv);
            }
        }
        return ans;
    }
};

// 使用 monotonic stack
// 很重要的一个道理:
// 以 A[i] 为最小值可以形成的子数组的数量 = i 到左边界的距离 * i 到右边界的距离。

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return helper(nums, less<int>()) - helper(nums, greater<int>());
    }


    long helper(vector<int>& nums, std::function<bool (int,int)> comp) {
        int n = nums.size();
        long ans=0;
        vector<int> st;
        for (int i=0;i<=n;i++) {
            // 这里不用在最后插入一个最大值或者最小值，直接进入循环把stack里的数弹出
            while (!st.empty() && (i==n || comp(nums[st.back()], nums[i]))) {
                int j=st.back();
                st.pop_back();
                int k = st.empty()?-1:st.back();
                ans+=(long)(i-j)*(j-k)*nums[j];
            }
            st.push_back(i);
        }
        return ans;
    }
};

