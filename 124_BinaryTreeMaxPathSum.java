class BinaryTreeMaxPathSum {
  int res;
  public int maxPathSum(TreeNode root) {
    res = Integer.MIN_VALUE;
    dfs(root);
    return res;
  }

  int dfs(TreeNode node) {
    if (node==null) return 0;
    int l = dfs(node.left), r = dfs(node.right);
    int sum = node.val + l + r;
    if (sum>res)
      res = sum;
    return Math.max(Math.max(node.val+l, node.val+r), 0);
  }
}