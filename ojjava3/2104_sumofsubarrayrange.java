
/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 

Follow-up: Could you find a solution with O(n) time complexity?
公式:
左边界有 (j-k) 种选择
右边界有 (i-j) 种选择
总子数组数就是乘积
当遍历到index=2，即元素3的时候，弹出






好的，我们用数组 [1,2,3] 来详细画出整个 helper 函数的执行过程，看看栈的变化和贡献计算。这样你能直观理解公式 (i - j) * (j - k) * nums[j]。

情况一：计算最大值贡献（comp = (a,b)->a<b）
初始
stack = []

ans = 0

i=0
入栈：stack = [0]

i=1
nums[stack.peek()] = 1，nums[1] = 2，满足 1 < 2 → 弹栈

j=0, k=-1

贡献 = (1-0)*(0-(-1))*nums[0] = 1*1*1 = 1

ans=1

入栈：stack=[1]

i=2
nums[1]=2 < nums[2]=3 → 弹栈

j=1, k=-1

贡献 = (2-1)*(1-(-1))*2 = 1*2*2 = 4

左边界为什么要设成 -1
当栈为空时，说明在 j 的左边没有比它更大（或更小）的元素来限制它。
换句话说，nums[j] 可以延伸到数组最左端。
所以我们人为设定一个“哨兵”位置 k = -1，代表左边界在数组外。
这样 (j - k) 就变成 (j - (-1)) = j+1，表示左边界可以从 0 到 j，一共有 j+1 种选择。

右边界选择数 (i - j)  
从 j=1 到 i-1=1，右边界只有一种选择：就是位置 1 本身。

左边界选择数 (j - k)  
从 k+1=0 到 j=1，左边界可以是 0 或 1，两种选择。

子数组总数  
左边界 × 右边界 = 2 × 1 = 2 个子数组。

这些子数组是什么？

[2] （左=1，右=1）

[1,2] （左=0，右=1）

在这两个子数组里，最大值都是 2。

贡献值  
每个子数组贡献 nums[j]=2，一共 2 个子数组，所以总贡献 = 2 × 2 = 4。


ans=5

入栈：stack=[2]

==
i=3 (末尾强制清空)
弹栈：j=2, k=-1

贡献 = (3-2)*(2-(-1))*3 = 1*3*3 = 9

ans=14

入栈：stack=[3]

最大值总和 = 14



 */
import java.util.*;
import java.util.function.BiPredicate;

class Solution {
    public long subArrayRanges1(int[] nums) {
        long ans = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int max = nums[i], min = nums[i];
                for (int k = i; k <= j; k++) {
                    max = Math.max(max, nums[k]);
                    min = Math.min(min, nums[k]);
                }
                ans += max - min;
            }
        }
        return ans;
    }

    public long subArrayRanges(int[] nums) {
        return helper(nums, (a, b) -> a < b) - helper(nums, (a, b) -> a > b);
    }

    private long helper(int[] nums, BiPredicate<Integer, Integer> comp) {
        int n = nums.length;
        long ans = 0;
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i <= n; i++) {
            while (!stack.isEmpty() && (i == n || comp.test(nums[stack.peekLast()], i < n ? nums[i] : 0))) {
                int j = stack.pollLast();
                int k = stack.isEmpty() ? -1 : stack.peekLast();
                ans += (long) (i - j) * (j - k) * nums[j];
            }
            stack.addLast(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = { 1, 2, 3 };
        System.out.println(sol.subArrayRanges(nums)); // 输出 4
    }
}