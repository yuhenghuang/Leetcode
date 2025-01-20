import java.util.*;

public class KthSmallestInBST {
  public int kthSmallest(TreeNode root, int k) {
    Stack<TreeNode> stack = new Stack<>();
    int cnt=0;
    while (!stack.isEmpty() || root!=null) {
      while (root.left!=null) {
        stack.push(root);
        root=root.left;
      }
      root=stack.pop();
      cnt++;
      if (cnt==k) return root.val;
      root=root.right;
    }
    return 0;
  }
}