#include <vector>
using namespace std;

// 不需要dp数组，使用f1,f2即可，表示前面两个位置能达到的最大值
// 对于每个位置，可以选择f2+nums[i],或者f1(前一个位置的最大值)

int solution(vector<int> nums) {    
    if (nums.empty()) return 0;    
    int f2=0;
    int f1=nums[0];
    int ans=f1;
    // 0-> f1, 1->ans,
    for (int i=1;i<nums.size();i++) {
        ans=max(f1,f2+nums[i]);        
        f2=f1;
        f1=ans;
    }    
    return ans;
}
