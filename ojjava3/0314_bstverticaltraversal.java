/*
描述
给定二叉树，返回其节点值的垂直遍历顺序。 (即逐列从上到下)。
如果两个节点在同一行和同一列中，则顺序应 从左到右。

对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col - 1) 和 (row + 1, col + 1) 。树的根结点位于 (0, 0) 。

LintCode企业/校园版——在线编程测评解决方案

候选人笔试筛选、团队能力测评、编程教学练习、在线考试评分
高校教师教育认证可享免费使用资格，数量有限

扫码咨询微信


样例
样例1

输入： {3,9,20,#,#,15,7}
输出： [[9],[3,15],[20],[7]]
解释：
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
样例2

输入： {3,9,8,4,0,1,7}
输出：[[4],[9],[3,0,1],[8],[7]]
解释：
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7

 lintcode 651
 leetcode 314
 goldman sachs 考题 

*/

import java.util.*;

public class Solution {
    static class Pair {
        TreeNode node;
        int column;

        Pair(TreeNode node, int column) {
            this.node = node;
            this.column = column;
        }
    }

    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();

        Deque<Pair> queue = new ArrayDeque<>();
        queue.offer(new Pair(root, 0));
        while (!queue.isEmpty()) {
            Pair p = queue.poll();            
            map.computeIfAbsent(p.column,k->new ArrayList<>());
            map.get(p.column).add(p.node.val);
            if (p.node!=null) queue.offer(new Pair(p.node.left, p.column-1);
            if (p.node!=null) queue.offer(new Pair(p.node.right, p.column+1);            
        }
        
        return ans;
    }
}
