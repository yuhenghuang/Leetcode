class DeleteNodeinBST {
  public TreeNode deleteNode(TreeNode root, int key) {
    if (root==null) return root;

    if (root.val > key)
      root.left = deleteNode(root.left, key);
    else if (root.val < key)
      root.right = deleteNode(root.right, key);
    else {
      if (root.left==null && root.right==null)
        return null;
      else if (root.left==null)
        return root.right;
      else if (root.right==null)
        return root.left;
      else {
        TreeNode temp = root.left;
        while (temp.right!=null)
          temp = temp.right;
        temp.right = root.right;
        return root.left;
      }
    }
    return root;
  }
}