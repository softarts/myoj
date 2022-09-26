#include <iostream>
using namespace std;




#include <unordered_set>
#include <string>

class Solution {
public:

// 找出两个数之间的完全平方数
// 1<=a<=b
// Input :  a = 3, b = 8
// Output : 1
// The only perfect in given range is 4.

// Input : a = 9, b = 25
// Output : 3
// The three squares in given range are 9,
// 16 and 25
    int vf1(int a, int b)
    {
        if (a < 0)
            a = 1;  // 0?
        if (b < 0)
            return 0;

        int l = ceil(sqrt(a));   // smaller integer no less than it
        int u = sqrt(b);
        if (l > u)
            return 0;
        else
            return u - l + 1;
    }
//vf2
// Two non-negative numbers N and M are called similar if their decimal representations (without leading zeros) can be obtained from each other by rearranging the digits. For example, in each of the following pairs one integer is similar to the other.

// 123 and 321
// 52832 and 22835
// 12 and 21
// Write a function such that given a non-negative integer N returns the number of non-negative integers similar to N.

// For example, given N=1213 the function should return 12 because there are twelve integers similar to 1213 namely:

// 1123, 1132, 1213, 1231, 1312, 1321, 2113, 2131, 2311, 3112, 3121 and 3211.

// If N = 0, it should return 1.

// If N = 100, it should also return 1 as 010 or 001 is not valid.
    int vf2(int n) {
        if (n==0) return 1;
        auto s = to_string(n);
        unordered_set<int> set;
        do {
            set.insert(stoi(s));
        } while ( std::next_permutation(s.begin(),s.end()) );
        return s.size();
    }
// LC413, 找出等比数列的个数，注意，如果该数列长度为4，那么可以构成3个数列
// vf_3
    //vf_4
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
 * LC2249
*/
    

};