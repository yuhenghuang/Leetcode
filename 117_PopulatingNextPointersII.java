class PopulatingNextPointersII extends PopulatingNextPointers {
  // BFS is the same
  // Thus only DFS (recursive) approach
  public Node connect(Node root) {
    dfs(root);
    return root;
  }

  public void dfs(Node node) {
    if (node==null || (node.left==null && node.right==null)) return;

    if (node.left!=null && node.right!=null) 
      node.left.next = node.right;
    Node p = node.right!=null?node.right:node.left;
    Node q = node.next;

    // ....
    while (q!=null && q.left==null && q.right==null)
      q = q.next;
    
    p.next = q!=null?(q.left!=null?q.left:node.next.right):null;

    // ....
    dfs(node.right);
    dfs(node.left);
  }
}