/*
You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

 

Example 1:



Input: n = 2, m = 1, hBars = [2,3], vBars = [2]

Output: 4

Explanation:

The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].

One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

Example 2:



Input: n = 1, m = 1, hBars = [2], vBars = [2]

Output: 4

Explanation:

To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.

Example 3:



Input: n = 2, m = 3, hBars = [2,3], vBars = [2,4]

Output: 4

Explanation:

One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.

和gic 2022 Q3有点类似
先全部移除，再找出最大的square

 */

import java.util.*;

class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);
        
        
        int h = findMaxLen(hBars);
        int v = findMaxLen(vBars);
        int l = Math.min(h,v);
        return l*l;
    }

    private int findMaxLen(int[] bars) {
        if (bars.length == 0) return 1;
        int prev = bars[0];
        int maxLen = 2;
        int curMaxLen = 2;
        for (int i = 1; i < bars.length; i++) {
            if (bars[i]==prev+1) {
                curMaxLen++;
                maxLen = Math.max(curMaxLen, maxLen);
            } else {
                // maxLen = Math.max(curMaxLen, maxLen);
                curMaxLen = 2;
            }
            prev = bars[i];
        }
        return maxLen;
    }

    public static void main(String[] args) {
        
        Solution solution = new Solution();
        
        int n=3, m=3;
        int[] hBars ={3,2,4};
        int[] vBars ={3,2};
        
        System.out.println("测试结果: " + solution.maximizeSquareHoleArea(n,m,hBars,vBars));
    }
}