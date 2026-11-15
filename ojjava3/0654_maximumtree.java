/*
You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.

 

Example 1:


Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
Example 2:


Input: nums = [3,2,1]
Output: [3,null,2,null,1]
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
All integers in nums are unique.

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/*
我原来递归的做法就是卡在找出最大点，然后再找出左边，右边的次大点，每一次都要找的话搜索量很惊人
所以想办法在前面遍历的时候就做好这些大小关系,就算没有stack，也可以用任何一个变量来代替保存stack.peek

这道题非常精彩，需要观察树的特点
先分解为一个局部，最大的为根节点，left是左边次小的，right是右边次小的

对于任何一个数，数组中顺序进来比他小的节点一定是其右树(因为在右侧)
对于已有的树，当进来一个更大的数，已有的树一定挂到大数的左树上

stack天然适合先构造一个局部成立的状态
每次进来一个新的数，都可以维持这个局部状态(也有点动态规划的意图)


*/

import java.util.*;

class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            TreeNode curr = new TreeNode(nums[i]);
            // if (!stack.isEmpty() && stack.peek().val > nums[i]) {
            //     stack.peek().right = curr;
            //     stack.push(curr);
            // } else {
            //     // < 
            //     while (!stack.isEmpty() && stack.peek().val < nums[i]) {
            //         curr.left = stack.pop();
            //     }
            //     // 不要遗漏这个,pop后stack里的元素的right已经改变了
            //     if (!stack.isEmpty()) {
            //         stack.peek().right = curr;
            //     }
            //     stack.push(curr);
            // }

            while (!stack.isEmpty() && stack.peek().val < nums[i]) {
                curr.left = stack.pop();
            }
            // 不要遗漏这个,pop后stack里的元素的right已经改变了
            if (!stack.isEmpty()) {
                stack.peek().right = curr;
            }
            stack.push(curr);
        }

        // 最后在最下面的就是root
        TreeNode root = null;

        while (!stack.isEmpty()) {
            root = stack.pop();
        }
        return root;
    }


    
}