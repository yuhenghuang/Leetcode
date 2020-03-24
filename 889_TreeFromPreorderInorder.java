class TreeFromPreorderInorder {
  public TreeNode constructFromPrePost(int[] pre, int[] post) {
    return recursive(0, pre.length-1, 0, post.length-1, pre, post);
  }

  public TreeNode recursive(int i, int j, int m, int n, int[] pre, int[] post) {
    if (i>j) return null;
    TreeNode node = new TreeNode(pre[i]);
    if (j-i==0) return node;
    int k;
    for (k=0; k<j-i; ++k)
      if (post[m+k]==pre[i+1]) break;
    node.left=recursive(i+1, i+k, m, m+k, pre, post);
    node.right=recursive(i+k+1, j, m+k+1, n-1, pre, post);
    return node;
  }
}