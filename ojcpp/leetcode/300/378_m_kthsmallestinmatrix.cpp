//
// Created by rui.zhou on 2/7/2019.
//
/*
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n^2.
 矩阵的行和列都是有序的，因此左上角最小，右下角最大
 */

#include <codech/codech_def.h>
#include <tuple>

using namespace std;

class Solution {
public:
    //m=n*n
    //m*log(m)*m
    int kthSmallest0(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        //O(M)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                arr.push_back(matrix[i][j]);
            }
        }
        //M*log(M)
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }

    // 思路 利用优先级队列，从左上角开始push进队列，
    // K*logM
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using mytuple=tuple<int,int,int>;
        auto comp = [](mytuple &lhs,mytuple&rhs){
            return std::get<0>(lhs) > std::get<0>(rhs);
        };

        std::priority_queue<mytuple,std::vector<mytuple>,decltype(comp) >q(comp);

        //class Compare = std::less<typename Container::value_type>> q;
        int n=matrix.size();
        // push first column
        for (int row=0;row<n;row++) {
            auto el = std::make_tuple(matrix[row][0],row,0);
            q.push(el);
        }
        int v,row,col;
        for (int j=1;j<k;j++) {
            std::tie(v, row, col) = q.top();
            q.pop();
            if (col+1==n) {
                continue;
            } else {
                q.push(std::make_tuple(matrix[row][col+1],row,col+1));
            }

        }

        std::tie(v, row, col) = q.top();
        return v;
    }
};


DEFINE_CODE_TEST(378_kthsmallestmatrix)
{
    Solution obj;
    {
        vector<vector<int>> nums{{1,5,9},{10,11,13},{12,13,15}};
        VERIFY_CASE(obj.kthSmallest(nums,8),13);
        VERIFY_CASE(obj.kthSmallest(nums,7),13);
        VERIFY_CASE(obj.kthSmallest(nums,1),1);
        VERIFY_CASE(obj.kthSmallest(nums,9),15);
        VERIFY_CASE(obj.kthSmallest(nums,2),5);
    }

}

