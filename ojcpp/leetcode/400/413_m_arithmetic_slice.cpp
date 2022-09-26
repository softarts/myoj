//
// Created by rui.zhou on 3/18/2019.
//
/*
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution0 {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            int count = 0;
            int addend = 0;

            for (int i = 2; i < A.size(); i++)
                if (A[i - 1] - A[i] == A[i - 2] - A[i - 1])
                    count += ++addend;
                else
                    addend = 0;

            return count;
        }
    };

    class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            auto calc = [](int sz)
            {
                return  (sz-1)*(sz-2) / 2;
            };
            size_t n = A.size();

            if (n<3)
                return 0;

            int begin = 0,end = 1,count = 0, step = A[1] - A[0];

            for (int cur = 2; cur<n; cur++)
            {
                if (A[cur] - A[end] == step)
                {
                    end++;
                }
                else
                {
                    count += calc(end - begin + 1);
                    begin = end;
                    end = cur;
                    step = A[end] - A[begin];
                }
            }
            count += calc(end - begin + 1);
            return count;
        }
    };
}

DEFINE_CODE_TEST(413_arithmetic_slice)
{
    Solution0 obj;
    {
        vector<int> nums{1,3,5,6,7,9,11};
        cout << obj.numberOfArithmeticSlices(nums);
    }

}