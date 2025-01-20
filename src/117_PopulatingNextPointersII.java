class PopulatingNextPointersII extends PopulatingNextPointers {
  public static void main(String[] args) {
    for (int i=1; i<10; ++i) {
      System.out.print(i+"\t");
      for (int j=1; j<=i; j++) 
        System.out.print(i*j+"\t");
      System.out.println("");
    }
    System.out.print("\t");
    for (int i=1; i<10; ++i) {
      System.out.print(i+"\t");
    }

  }
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