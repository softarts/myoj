//
// Created by rui zhou on 31/03/19.
//

/*
 * 有一道题是问篮子里能放多少苹果，给你一个数组，0的位置是篮子已经有的重量，剩下的是每个苹果。贪心就可以了。
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    // O(N*LogN)
    int solution(vector<int> &nums) {
        int capacity = 5000-nums[0];
        int sum=0;
        sort(nums.begin()+1,nums.end());
        int total=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]+sum<=capacity) {
                sum+=nums[i];
                total++;
            } else {
                break;
            }
        }
        return total;
    }
}


DEFINE_CODE_TEST(vf_2018_maxapple) {
    {
        vector<int> nums{4850,100,30,30,100,50,100};
        VERIFY_CASE(solution(nums),3);
    }
    {
        vector<int> nums{4650,150,150,150};
        VERIFY_CASE(solution(nums),2);
    }

}