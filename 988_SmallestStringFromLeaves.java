class SmallestStringFromLeaves {
  public String smallestFromLeaf(TreeNode root) {
    return dfs(root);
  }

  String dfs(TreeNode node) {
    char c = (char) ('a' + node.val);
    if (node.left==null && node.right==null) return Character.toString(c);

    if (node.left!=null && node.right==null) return dfs(node.left) + c;
    if (node.left==null && node.right!=null) return dfs(node.right) + c;
    String l = dfs(node.left), r = dfs(node.right);
    return (l.compareTo(r)<0? l : r) + c;
  }
}