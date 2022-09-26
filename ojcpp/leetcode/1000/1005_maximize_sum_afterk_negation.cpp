//
// Created by rui.zhou on 3/10/2019.
//

/* contest 127
 * Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.



Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
Example 2:

Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
Example 3:

Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].


Note:

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
 * 1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
 */
#include <codech/codech_def.h>
using namespace std;

namespace c127 {
    class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& A, int K) {
            auto comp=[](int&a,int&b) {
                return a>b;
            };
            priority_queue<int,vector<int>,decltype(comp)> pq(comp);
            int sum=0;
            for (auto &iter:A) {
                pq.push(iter);
                sum+=iter;
            }
            int count=0;
//            if (K==0)
//                return sum;
            //int maxSum=INT_MIN;
            while (count<K) {
                int c=pq.top();
                sum=sum-c-c;
                //maxSum=max(sum,maxSum);
                pq.pop();
                pq.push(-c);
                count++;
            }
            return sum;
        }
    };
}

DEFINE_CODE_TEST(1005_maximizesum)
{
    c127::Solution obj;
    {
        vector<int> nums{5,6,9,-3,3};
        VERIFY_CASE(obj.largestSumAfterKNegations(nums,2),20);
    }
    {
        vector<int> nums{5,6,9,-3,3};
        VERIFY_CASE(obj.largestSumAfterKNegations(nums,0),20);
    }
    {
        vector<int> nums{4,2,3};
        VERIFY_CASE(obj.largestSumAfterKNegations(nums,1),5);
    }
    {
        vector<int> nums{3,-1,0,2};
        VERIFY_CASE(obj.largestSumAfterKNegations(nums,3),6);
    }
    {
        vector<int> nums{2,-3,-1,5,-4};
        VERIFY_CASE(obj.largestSumAfterKNegations(nums,2),13);
    }


}