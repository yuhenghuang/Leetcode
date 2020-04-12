import java.util.Stack;

class PathSum {
  public boolean hasPathSum(TreeNode root, int sum) {
    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);
    while (!stack.isEmpty()) {
      root = stack.pop();
      if (root==null) continue;
      if (root.left==root.right && root.val==sum)
        return true;

      if (root.left!=null) {
        root.left.val+=root.val;
        stack.push(root.left);
      }
      if (root.right!=null) {
        root.right.val+=root.val;
        stack.push(root.right);
      }
    }
    return false;
  }

  int target;
  public boolean hasPathSumdfs(TreeNode root, int sum) {
    target = sum;
    return dfs(root, 0);
  }

  public boolean dfs(TreeNode root, int cur) {
    if (root==null) return false;
    int next = cur+root.val;
    if (root.left==null && root.right==null)
      if (next==target) return true;
      else return false;
    return dfs(root.left, next) || dfs(root.right, next);
  }
}