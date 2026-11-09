/*
Description
You are given all the nodes of an N-ary tree as an array of Node objects, where each node has a unique value.

Return the root of the N-ary tree.

Custom testing:

An N-ary tree can be serialized as represented in its level order traversal where each group of children is separated by the null value (see examples).



For example, the above tree is serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

The testing will be done in the following way:

The input data should be provided as a serialization of the tree.
The driver code will construct the tree from the serialized input data and put each Node object into an array in an arbitrary order.
The driver code will pass the array to findRoot, and your function should find and return the root Node object in the array.
The driver code will take the returned Node object and serialize it. If the serialized value and the input data are the same, the test passes.
 

Example 1:



Input: tree = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
Explanation: The tree from the input data is shown above.
The driver code creates the tree and gives findRoot the Node objects in an arbitrary order.
For example, the passed array could be [Node(5),Node(4),Node(3),Node(6),Node(2),Node(1)] or [Node(2),Node(6),Node(1),Node(3),Node(5),Node(4)].
The findRoot function should return the root Node(1), and the driver code will serialize it and compare with the input data.
The input data and serialized Node(1) are the same, so the test passes.
Example 2:



Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 

Constraints:

The total number of nodes is between [1, 5 * 104].
Each node has a unique value.
 

Follow up:

Could you solve this problem in constant space complexity with a linear time algorithm?


https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1506.Find%20Root%20of%20N-Ary%20Tree/README_EN.md
*/


/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
利用XOR
1 XOR 1 = 0
5 XOR 6 = 1 

异或运算（XOR，符号为 ^）的核心特点可以概括为一句话：“相同为 0，不同为 1”。
在算法和位运算中，它有以下几个极其重要的数学性质和应用特性：

1. 核心数学性质

• 归零律：x ^ x = 0 （任何数和自己异或，结果都是 0）
• 恒等律：x ^ 0 = x （任何数和 0 异或，结果仍是它本身）
• 交换律：a ^ b = b ^ a
• 结合律：(a ^ b) ^ c = a ^ (b ^ c)

2. 为什么它能用来找 N 叉树的根节点？

结合上面的性质，异或运算有一个延伸特性：在一堆无序的数字中，如果某个数字出现了偶数次（比如 2 次），它就会在累加异或的过程中自己把自己抵消掉（变成 0）；而出现奇数次（比如 1 次）的数字则会被保留下来。
这使得它具备了以下两个独特的应用优势：
• 顺序无关性：因为有交换律和结合律，无论你先异或哪个节点、后异或哪个节点，最终的计算结果都完全一样。
• 空间复杂度 \(\mathcal{O}(1)\)：你不需要像哈希表（Set）那样开辟额外的内存去记录谁是谁的子节点，只需要一个变量 val_sum 一路异或到底，就能像“消消乐”一样把所有非根节点全部消去。

这个题和goldman sachs forest其实并不像，那个是并查集
 */
class Solution {
    public Node findRoot(List<Node> tree) {
        int x = 0;
        for (Node node : tree) {
            x ^= node.val;
            for (Node child : node.children) {
                x ^= child.val;
            }
        }
        for (int i = 0;; ++i) {
            if (tree.get(i).val == x) {
                return tree.get(i);
            }
        }
    }

    // 还有一个方法是用hashmap,找出没有parent的就是root
    static Node findRoot(List<Node> tree)
    {
        Map<Node, Node> parents = new HashMap<>();

        // Iterate over each node and its children
        for (Node node : tree) {
            for (Node child : node.children) {
                parents.put(child, node);
            }
        }

        // Find the root node by checking for a node without
        // a parent
        for (Node node : tree) {
            if (!parents.containsKey(node)) {
                return node;
            }
        }

        // No root found
        return null;
}


