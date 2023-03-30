
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root==null) return root;
        invertTree(root.left);
        invertTree(root.right);
        TreeNode tmp = root.left;
        root.left=root.right;
        root.right=tmp;
        return root;
    }

    @SuppressWarnings ("unchecked")
    public static void main(String []args) {
        TreeNode root=new TreeNode(1);
        TreeNode ret = new Solution().invertTree(root);        
        System.out.println("0226=>"+ret.val);
    }
}
