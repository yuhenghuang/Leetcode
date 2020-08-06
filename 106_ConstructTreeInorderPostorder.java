class ConstructTreeInorderPostorder {
  public TreeNode buildTree(int[] inorder, int[] postorder) {
    return recursive(0, 0, inorder.length-1, inorder, postorder);
  }

  TreeNode recursive(int i, int j, int len, int[] inorder, int[] postorder) {
    if (len<0) return null;
    TreeNode root = new TreeNode(postorder[j+len]);
    if (len==0)
      return root;

    int k=0;
    while (inorder[i+k]!=postorder[j+len])
      ++k;

    root.left = recursive(i, j, k-1, inorder, postorder);
    root.right = recursive(i+k+1, j+k, len-k-1, inorder, postorder);
    return root;
  }
}