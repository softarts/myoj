//
// Created by rui zhou on 2020-06-21.
//

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 */

// 
#include <codech/codech_def.h>

using namespace std;

// 如何判断rectangle是个问题
//

namespace {
    class Solution {
    public:        
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty()) return 0;
            int row = matrix.size();
            int col = matrix[0].size();
            int maxArea=0;    
            for (int i=row-1;i>=0;i--) {
                vector<int> heights;
                for (int j=0;j<col;j++) {
                    int h = 0;
                    //从底到上，对每一行计算一个高度，如果该行起始为0，则记为0
                    for (int k=i;k>=0&&matrix[k][j]=='1';k--) {    
                        h+=1;
                    //cout<<matrix[k][j]<<","<<k<<","<<j<<"="<<h<<endl;
                    }
                    heights.push_back(h);
                }
                // find max rectangle;
                //for (auto v:heights) {cout << v<<" ";}
                //cout<<endl;
                maxArea = max(maxArea,findMaxArea(heights));
                //cout<<"row="<<i<<","<<maxArea<<endl;
            }
            return maxArea;
        }

    // deque都是放入波峰上升的高度,因此需要从deque中pop出元素(A1)，计算其宽度时，就是到前一个元素A0(比它低)的距离
    // 如果deque是空的，证明从0开始一直都是>=这个高度
    // lc084的做法
        int findMaxArea(vector<int> &heights) {
            deque<int> deq;
            int maxArea=0;
            heights.push_back(0);
            for (int i=0;i<heights.size();i++) {
                if (deq.empty() || heights[deq.back()]<heights[i]) {
                    deq.push_back(i);
                } else {
                    int prevPos = deq.back();
                    deq.pop_back();
                    maxArea = max(maxArea,heights[prevPos]*(deq.empty()?i:(i-deq.back()-1)));
                    cout<<"max"<<i<<","<<maxArea<<endl; 
                    i--;
                }
            }
            return maxArea;
        }
    };
}