/*
You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
Example 2:

Input: nums = [100]
Output: 0

这段代码是整个算法的核心递推部分。它通过数学规律（而非重复遍历计算每个 $F(k)$）在 $O(n)$ 的时间复杂度内，依次求出 $F(1)$ 到 $F(n-1)$，并不断更新最大值。逐行详细解释for (int i = 1; i < n; i++)从 $i = 1$ 开始循环到 $n-1$，分别代表计算第 $1$ 次旋转到第 $n-1$ 次旋转的值 $F(1), F(2), \dots, F(n-1)$（初始的 $F(0)$ 已经在循环外计算好了）。f = f + sum - n * nums[n - i]; (核心递推公式)这行代码利用了前一项 $F(k-1)$ 推导当前项 $F(k)$ 的数学递推关系式：$$F(k) = F(k-1) + \text{sum} - n \cdot \text{nums}[n - k]$$原理解析：+ sum：当数组顺时针旋转一位时，除了即将移到最前面的那个元素外，其余所有元素的下标（权重）都向右移动了一位，即全部增加了 $1$。所有元素的权重各增加 $1$，增加的总和正好等于整个数组的和 sum。- n * nums[n - i]：原来在数组尾部的那个元素被旋转到了最前面（下标变成 $0$），它的权重从原本的 $(n-1)$ 骤降为 $0$。数学上推导发现，为了纠正这个元素的权重变化，需要减去 $n$ 倍的该元素值。maxVal = Math.max(maxVal, f);每次计算出当前的新旋转值 f 后，与之前记录的最大值进行比较，把较大的那个存入 maxVal，确保循环结束后能得到全局最大值。
*/

class Solution {
    public int maxRotateFunction(int[] nums) {
        long f = 0;
        long sum = 0;
        for (int i=0;i<nums.length;i++) {
            sum += nums[i];
            f += i*nums[i];
        }
        long maxf = f;
        int n = nums.length;
        // 旋转的次数
        for (int j=1;j<n;j++) {
            f = f + sum - n*nums[n-j];  
            // nnums[n-j] 排在末位的元素，*n,而不是n-1，因为前面统一加了n，意味着多加1个nums[j-j]
            maxf = Math.max(maxf,f);
        }
        return (int)maxf;
    }
}
