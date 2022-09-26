//
// Created by rui.zhou on 3/10/2019.
//

/* contest 127
 * In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.



Example 1:



Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation:
In this case, it is not possible to rotate the dominoes to make one row of values equal.


Note:

1 <= A[i], B[i] <= 6
2 <= A.length == B.length <= 20000
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int minCost= std::numeric_limits<int>::max();
        for (int domino=1;domino<=6;domino++) {
            int a_cost=0,b_cost=0;
            for (int i=0;i<A.size();i++) {
                if (A[i]!=domino && B[i]!=domino) {
                    a_cost=std::numeric_limits<int>::max();
                    b_cost=std::numeric_limits<int>::max();
                    break;
                } else if (A[i]!=domino) {
                    a_cost++;
                } else  if (B[i]!=domino){
                    b_cost++;
                }
            }
            minCost=min(minCost,min(a_cost,b_cost));
        }
        return minCost== INT_MAX?-1:minCost;
    }
};

DEFINE_CODE_TEST(1007_domino) {
    Solution obj;
    {
        vector<int> a{2,1,2,4,2,2},b{5,2,6,2,3,2};
        VERIFY_CASE(obj.minDominoRotations(a,b),2);
    }
    {
        vector<int> a{3,5,1,2,3},b{3,6,3,3,4};
        VERIFY_CASE(obj.minDominoRotations(a,b),-1);
    }
    {
        vector<int> a{1,2,1,1,1,2,2,2},b{2,1,2,2,2,2,2,2};
        VERIFY_CASE(obj.minDominoRotations(a,b),1);
    }
}