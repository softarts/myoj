
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }


    public static TreeNode createTree(ArrayList<Integer> arr) {
        TreeNode root=new TreeNode(arr.get(0));
        LinkedList<TreeNode> toDo=new LinkedList(Arrays.asList(root));

        int idx = 0;
        while (!toDo.isEmpty()) {
            TreeNode parent = toDo.getFirst();
            toDo.pop();
            idx++;
            if (idx>=arr.size()) break;
            var left = arr.get(idx);
            if (left!=null) {
                parent.left = new TreeNode(left);
                toDo.offer(parent.left);//push 是插到linkedlist起始，faint!
            } else {
                parent.left = null;
            }

            // right
            idx++;
            if (idx>=arr.size()) break;
            var right = arr.get(idx);
            if (right!=null) {
                parent.right = new TreeNode(right);
                toDo.offer(parent.right);
            } else {
                parent.right = null;
            }
        }
        return root;
    }
}