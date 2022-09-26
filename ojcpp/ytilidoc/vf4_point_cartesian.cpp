//
// Created by rui zhou on 29/03/19.
//

/*
 * a point in a two dimensional cartesian plane is called a lattice point if both of its coordinates are integers
 * write a function:

* int solution(int N):
 * given a non-negative integer N,returns the number of lattice points lying inside or on the edge of a disc of
 * radius N which is centered at (0,0) the function should return -1 if this number exceeds 1,0000,0000,0000
 * for example, given N=2, the function should return 13, because there are thirteen points
 * lying inside or on the edge of disc of radius 2centered at (0,), as indicated in the following image
 *
 * raidus - 2,
 *
 * assume that:
 * N is an integer within the range[0..20000]
 * complexity:
 * expetced worst-case time complexity is O(N)
 * expected worst space complexity is O(1)
 *
 */

//
//
#include <codech/codech_def.h>
#include <cmath>
using namespace std;

namespace {
    static int solution(int N)
    {
        int ans=0;
        int m=0,h=0;
        for (int i=N-1;i>0;i--) {
            if (sqrt(2*i*i) < N) {
                m=i;break;
            }
        }
        for (int i=m+1;i>0;i--) {
            if (sqrt((m+1)*(m+1)+i*i) < N) {
                h=i;break;
            }
        }
        ans+=(m*2+1)*(m*2+1);//m到(0，0) 半径距离小于N，因此点数是一个正方形， ROW*COL=(2M+1)^2
        ans+=(h*2+1)*4;  //还要考虑M+1到m 之间的点，这些点不在上面的范围内，但仍可能小于半径N
        return ans;
    }
}


DEFINE_CODE_TEST(vf4_point_catesian)
{
    VERIFY_CASE(solution(1),5);
    VERIFY_CASE(solution(2),13);
    VERIFY_CASE(solution(6),109);
}