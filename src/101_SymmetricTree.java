import java.util.Stack;

class SymmetricTree {
  public boolean isSymmetric(TreeNode root) {
    Stack<TreeNode> s1 = new Stack<>();
    Stack<TreeNode> s2 = new Stack<>();
    s1.push(root);
    s2.push(root);
    while (!s1.isEmpty() || !s2.isEmpty()) {
      TreeNode n1 = s1.pop();
      TreeNode n2 = s2.pop();
      if (n1==null || n2==null) {
        if (n1!=n2) 
          return false;
      }
      else {
        if (n1.val!=n2.val) return false;
        s1.push(n1.left);
        s2.push(n2.right);
        if (n1!=n2) {
          s1.push(n1.right);
          s2.push(n2.left);
        }
      }
    }
    return true;
  }

  public boolean isSymmetricDFS(TreeNode root) {
    return dfs(root, root);
  }

  private boolean dfs(TreeNode n1, TreeNode n2) {
    if (n1==null || n2==null) 
      if (n1==null && n2==null) return true;
      else return false;
    return n1.val==n2.val && dfs(n1.left, n2.right) && (n1==n2 || dfs(n1.right, n2.left));
  }
}