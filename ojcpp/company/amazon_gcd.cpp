//
// Created by rui.zhou on 2/24/2019.
//

/*
 * 找出一个数组中所有数的最大公约数
 * 2,4,6,8,10 -> 2
 *
 */

#include <codech/codech_def.h>
using namespace std;

// Euclidean algorithm
// a,b的最大公约数，b%a之后得到a+a1部分,再递归调用(a,a1)
// 直到两者相等，或者有一个为0
// 15,9=>3 转化为6,9
int gcd(int a,int b) {
    if (a==0)
        return b;
    return gcd(b%a,a);
}
int generalizedGCD(int num, int* arr)
{
    int result = arr[0];
    for (int i=1;i<num;i++) {
        result = gcd(arr[i],result);
    }
    return result;
}

DEFINE_CODE_TEST(amazon_gcd)
{
    {
        vector<int> nums{2,4,6,8,10};
        VERIFY_CASE(generalizedGCD(nums.size(),&nums[0]),2);
    }
    {
        vector<int> nums{1,4,6,8,10};
        VERIFY_CASE(generalizedGCD(nums.size(),&nums[0]),1);
    }
    {
        vector<int> nums{2,3,4,5,6};
        VERIFY_CASE(generalizedGCD(nums.size(),&nums[0]),1);
    }
    {
        vector<int> nums{10,10,10,10,10};
        VERIFY_CASE(generalizedGCD(nums.size(),&nums[0]),10);
    }
}


