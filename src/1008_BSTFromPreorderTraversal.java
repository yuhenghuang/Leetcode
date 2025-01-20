class BSTFromPreorderTraversal {
  int[] arr;
  public TreeNode bstFromPreorder(int[] preorder) {
    arr = preorder;
    return dfs(0, preorder.length-1);
  }

  public TreeNode dfs(int i , int j) {
    if (i>j) return null;
    TreeNode node = new TreeNode(arr[i]);
    if (i==j) return node;
    int k=i+1;
    while (k<=j && arr[k]<arr[i]) k++;
    node.left = dfs(i+1, k-1);
    node.right = dfs(k, j);
    return node;
  }
}