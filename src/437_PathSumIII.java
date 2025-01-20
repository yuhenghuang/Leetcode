class PathSumIII {
  public static void main(String[] args) {
    PathSumIII obj = new PathSumIII();
    TreeNode root = LeetcodeUtil.treeParser("[1,null,2,null,3,null,4,null,5]");
    System.out.println(obj.pathSum(root, 3));
  }

  public int pathSum(TreeNode root, int sum) {
    if (root==null) return 0;
    return dfs(root.left, root.val, sum) + dfs(root.right, root.val, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
  }

  int dfs(TreeNode root, int currSum, int sum) {
    if (root==null) return 0;
    currSum += root.val;
    return dfs(root.left, currSum, sum) + dfs(root.right, currSum, sum) + (currSum==sum?1:0);
  }
}