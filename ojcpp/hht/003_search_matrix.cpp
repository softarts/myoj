//
// Created by rui zhou on 08/05/19.
//

// 每行，列都是递增的，如果找到，返回true，找不到返回false
//LC074
#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            if (m==0) return false;
            int n = matrix[0].size();

            int row=0,col=n-1;
            while (row >=0 && col >=0 && row < m && col <n) {
                int v = matrix[row][col];
                if (v==target) {
                    return true;
                } else if (v<target) {
                    row++;
                } else if (v>target) {
                    col--;
                }
            }
            return false;
        }
    };
}


DEFINE_CODE_TEST(hht_003_search2dmatrix)
{
    Solution obj;
    {
        vector<vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
        VERIFY_CASE(obj.searchMatrix(m,3),true);
        VERIFY_CASE(obj.searchMatrix(m,13),false);
    }
    {
        vector<vector<int>> m{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
        VERIFY_CASE(obj.searchMatrix(m,5),false);
        VERIFY_CASE(obj.searchMatrix(m,7),true);
    }

}
