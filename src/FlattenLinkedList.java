//import java.util.Queue;
//import java.util.ArrayDeque;
import java.util.Stack;

public class FlattenLinkedList {
  public Node flatten(Node head) {
    Stack<Node> stack = new Stack<>();
    Node node = head;
    while (node!=null || !stack.isEmpty()) {
      while (node.next!=null && node.child==null) node=node.next;
      if (node.child!=null) {
        if (node.next!=null) stack.push(node.next);
        node.next=node.child;
        node.child.prev=node;
        node.child=null;
      } 
      else if (!stack.isEmpty()){
        node.next=stack.pop();
        node.next.prev=node;
      }
    }
    return head;
  }

  public Node flattendfs(Node head) {
    dfs(head);
    return head;
  }

  public void dfs(Node head) {
    if (head==null) return;
    else if (head.child==null) dfs(head.next);
    else {
      Node next = head.next;
      dfs(next);
      dfs(head.child);
      head.next=head.child;
      head.child.prev=head;
      head.child=null;
      if (next!=null) {
        while (head.next!=null) head=head.next;
        head.next=next;
        next.prev=head;
      }
    }
  }

  class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
  }
}