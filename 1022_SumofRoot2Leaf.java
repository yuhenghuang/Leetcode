class SumofRoot2Leaf {
  int res;
  public int sumRootToLeaf(TreeNode root) {
    res = 0;
    sumRootToLeaf(root, 0);
    return res;
  }

  void sumRootToLeaf(TreeNode root, int val) {
    if (root==null) return;

    val = (val << 1) + root.val;
    if (root.left==null && root.right==null) {
      res += val;
      return;
    }

    sumRootToLeaf(root.left, val);
    sumRootToLeaf(root.right, val);
  }
}
