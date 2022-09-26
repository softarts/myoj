//
// Created by rui.zhou on 9/27/2019.
//

/*
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].  or [1,3,2,3,1,2]
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

如何解决  1,3,1,2,2,3 ? -> 1,3,2,3,1,2, 如何调整1(2), 2(3)的位置?
 1,3,1,2,  (2,3) -> 1,3,1,3, ...?

 思路
1) O(N*LogN)
 先sort， 分成left和right,left要多一个，保证单双数都行
然后放一个左边最大的数，放一个右边最大的数，这样可以保证右边一定比左边大(否则可能出现右边最小的=左边的数)
2)

 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int len = nums.size();
            vector<int> left(nums.begin(),nums.begin()+(len+1)/2); // 5-->3,4-->2
            vector<int> right(nums.begin()+(len+1)/2,nums.end());

            //cout<<PRINT_VEC(move(left)) << endl;
            //cout<<PRINT_VEC(move(right)) << endl;

            vector<int>::reverse_iterator liter = left.rbegin();
            vector<int>::reverse_iterator riter = right.rbegin();
            for (int i=0;i<len;i+=2) {
                nums[i]=*liter++;
            }
            for (int i=1;i<len;i+=2) {
                nums[i]=*riter++;
            }
        }
    };


//    class Solution {
//    public:
//        void wiggleSort(vector<int>& nums) {
//            int len = nums.size();
//            nth_element(nums.begin(),nums.begin()+len/2,nums.end());  // nth start from 0
//            cout << PRINT_VEC(move(nums))<<endl;
//
//            //1,2,3,4,5,6
//            //1,5,3,4,2,6
//            //1,
//
//            //1,5,3,4,2,6
//            //1,5,3,2,4,6
//
//            //2,1,4,3,5,6,7,8,9 ==>
//            //2,9,4,3,5,6,7,8,1
//            //2,9,4,7,5,6,3,8,1
//            int start = 1, end=len%2==0?len-2:len-1;
//            while (start<end) {
//                swap(nums[start],nums[end]);
//                start+=2;end-=2;
//            }
//        }
//    };
}

DEFINE_CODE_TEST(324_wigglesort2) {
    Solution obj;
    {
        vector<int> nums{4,5,5,6};
        obj.wiggleSort(nums);  //->5,5,4,6
        cout << PRINT_VEC(move(nums))<<endl; //5,6,4,5
    }

    {
        vector<int> nums{1,1,2,1,2,2,1};
        obj.wiggleSort(nums);
        cout << PRINT_VEC(move(nums))<<endl;
    }
    {
        vector<int> nums{1, 3, 2, 2, 3, 1};
        obj.wiggleSort(nums);
        cout << PRINT_VEC(move(nums))<<endl;
    }

}
//void wiggleSort(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    int len = nums.size();
//    vector<int> temp1(nums.begin(),ums.begin() + (len - 1) / 2 + 1);
//    vector<int> temp2(nums.begin() + (len - 1) / 2 + 1,nums.end());
//    reverse_iterator<vector<int>::iterator> riter(temp1.end());
//    for (int i = 0; i < len; i=i + 2){
//        nums[i] = *riter, riter++;
//    }
//    riter= reverse_iterator<vector<int>::iterator>(temp2.end());
//    for (int i = 1; i < len; i=i + 2)
//        nums[i] = *riter, riter++;
//}