//
// Created by rui.zhou on 9/26/2019.
//

/*
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

 O(n)时间内，应该不是DP,
 1,2,3,4,5->1,1,1,1
 5,4,3,2,1->-1,-1,-1,-1
 5,4,5,4,5->-1,1,-1,1  x
 5,4,5,3,4,5
 5,4,5,2,3,4  ok -> 2,3,4
 5,4,5,3,4,4  x
 5,4,5,3,3,6  x

 可能用2分法 x

 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            // 只要找到一个数比前两个都大即可.
            // m1 如果不为INT_MAX,表示前面已经出现了一对pair ,m0<m1;只要大于m1即可形成3个
            // 如果在m1之后重新形成一对新的m0,m1,也可以
            int m0 = INT_MAX, m1 = INT_MAX;
            for (auto n: nums) {
                if (n>m1) {
                    return true;
                } else if (n>m0) {
                    m1 = min(m1,n);
                } else {
                    m0 = min(m0,n);
                }
            }
            return false;
        }
    };
}
