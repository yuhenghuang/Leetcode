import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

class PopulatingNextPointers {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    //System.out.println(scan.nextLine());
    //System.out.println(scan.nextLine());
    int[][] nums = LeetcodeParser.array2dParser(scan.nextLine());
    for (int[] line : nums)
      System.out.println(Arrays.toString(line));
    scan.close();
  }
  public Node connect(Node root) {
    if (root!=null) dfs(root);
    return root;
  }

  public void dfs(Node node) {
    if (node.left==null) return;
    node.left.next = node.right;
    if (node.next!=null)
      node.right.next = node.next.left;
    dfs(node.left);
    dfs(node.right);
  }

  public Node connectBFS(Node root) {
    Queue<Node> queue = new ArrayDeque<>();
    if (root!=null) queue.offer(root);
    while (!queue.isEmpty()) {
      int N = queue.size();
      while (N-->0) {
        Node node = queue.poll();
        if (node.left!=null) {
          queue.offer(node.left);
          queue.offer(node.right);
        }
        if (N!=0) {
          node.next = queue.peek();
        }
      }
    }
    return root;
  }

  class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
  };
}