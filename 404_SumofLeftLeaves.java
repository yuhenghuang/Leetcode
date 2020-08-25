class SumOfLeftLeaves {
  public int sumOfLeftLeaves(TreeNode root) {
    if (root==null) return 0;
    return sumOfLeftLeaves(root.left, true) + sumOfLeftLeaves(root.right, false);
  }

  int sumOfLeftLeaves(TreeNode root, boolean left) {
    if (root==null) return 0;

    if (root.left==null && root.right==null && left)
      return root.val;
    else
      return sumOfLeftLeaves(root.left, true) + sumOfLeftLeaves(root.right, false);
  }
}