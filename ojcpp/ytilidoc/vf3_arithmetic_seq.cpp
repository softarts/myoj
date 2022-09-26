//
// Created by rui zhou on 29/03/19.
//

/*
 *
 * a sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between
 * any two consecutive elements is the same, for example, these are arithmetic swquences:
 * 1,3,5,7,9
 * 7,7,7,7,7
 * 3,-1,-5,-9
 * the sequence[1,1,2,5,7] is not arithmetic
 * a zero-indexed array a consisting of N numbers is given, a slice of the array is any pair of integers
 * (P,Q) such that 0 <= P < Q < N
 * a slice (P,Q) of array A is called arithmetic if the sequence:
 * A[P],A[P+1],...A[Q-1],A[Q]
 * is arithmetic, in particular, this means that P+1 < Q
 * write a function:
 * int solution(int A[],int N)
 * that,given array A consisting of N numbers, return the number of arithmetic slice in A
 * the function should return -1 if the result exceeds 1,0000,0000,0000
 *[-1,1,3,3,3,2,1,0]
 *the function should return 5 because there are five arithmetic slices of that array, namely:
 *(0,2),(2,4),(4,6),(4,7),(5,7)
 *
 * LC413
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    int solution(int a[],int n) {
        int add=0;
        int ans=0;
        for (int i=1;i<n-1;i++) {
            if (a[i-1]-a[i]==a[i]-a[i+1]) {
                ans += ++add;
            } else {
                add=0;
            }
        }
        return ans;
    }

    static int solution0(int a[], int n)
    {
        auto calc = [](int sz)
        {
            if (sz>=3)
            {
                sz=sz-2;
                return   (1 + sz)*sz / 2;
            }

            else
                return 0;
        };

        if (n<3)
            return -1;
        int begin = 0;
        int end = 1;
        int count = 0;
        int step = a[1]-a[0];
        for (int cur=2; cur<n;cur++)
        {
            if (a[cur]-a[end]==step)
            {
                end++;
            }
            else
            {
                count += calc(end-begin+1);
                begin = end;
                end = cur;
                step = a[end] - a[begin];
            }
        }
        count += calc(end - begin + 1);
        return count;
    }
}

DEFINE_CODE_TEST(vf3_arithmetic_subarry)
{
    int arr[] = {-1, 1, 3, 3, 3, 2, 1, 0};
    VERIFY_CASE(solution(arr,sizeof(arr)/sizeof(int)), 5);
}