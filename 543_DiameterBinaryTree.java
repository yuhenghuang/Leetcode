import java.util.Stack;

class DiameterBinaryTree {
  public int diameterOfBinaryTree(TreeNode root) {
    int res=0;
    Stack<TreeNode> stack = new Stack<>();
    while (stack.size()>1 || root!=null) {
      while (root!=null) {
        root.val = 1;
        stack.push(root);
        root = root.left;
      }
      while (stack.size()>1 && stack.peek().right==null) {
        int temp = stack.pop().val;
        if (stack.peek().val + temp - 1 >res) res = stack.peek().val + temp - 1;
        if (stack.peek().val>1) {
          stack.peek().val = Math.max(stack.peek().val, temp+1);
        }
        else
          stack.peek().val += temp;
      }
      if (!stack.isEmpty()) {
        root = stack.peek().right;
        stack.peek().right = null;
      }
    }
    return res;
  }

  int res;
  public int diameterOfBinaryTreeRec(TreeNode root) {
    res = 0;
    dfs(root);
    return res;
  }
  public int dfs(TreeNode root) {
    if (root==null) return -1;
    int left = dfs(root.left) + 1;
    int right = dfs(root.right) + 1;
    if (left+right>res) res=left+right;
    return Math.max(left, right);
  }
}