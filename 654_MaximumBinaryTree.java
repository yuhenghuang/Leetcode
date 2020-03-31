class MaximumBinaryTree {
  int[] nums;
  public TreeNode constructMaximumBinaryTree(int[] nums) {
    this.nums = nums;
    return dfs(0, nums.length-1);
  }

  private TreeNode dfs(int i, int j) {
    if (i>j) return null;

    int k=i;
    for (int l=i+1; l<=j; ++i)
      if (nums[l]>nums[k])
        k=l;

    TreeNode node = new TreeNode(nums[k]);
    node.left = dfs(i, k-1);
    node.right = dfs(k+1, j);
    return node;
  }
}