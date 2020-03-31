class MaxBinaryTreeII {
  public TreeNode insertIntoMaxTree(TreeNode root, int val) {
    if (root==null) return root;
    TreeNode dummy = new TreeNode(val);
    if (root.val<val) {
      dummy.left = root;
      return dummy;
    }

    TreeNode node = root;
    while (node.right!=null || node.right.val>val)
      node = node.right;
    
    dummy.left = node.right;
    node.right = dummy;
    return root;
  }
}