import java.util.*;

public class MinStack {

  /** initialize your data structure here. */
  Stack<Pair> stack;
  public MinStack() {
    stack = new Stack<>();
  }
  
  public void push(int x) {
    if (!stack.empty()) stack.push(new Pair(x, x));
    else stack.push(new Pair(x, stack.peek().min));
  }
  
  public void pop() {
    stack.pop();
  }
  
  public int top() {
    return stack.peek().val;
  }
  
  public int getMin() {
    return stack.peek().min;
  }

  class Pair {
    int val, min;
    Pair(int v, int m) {
      val = v;
      min = Math.min(v, m);
    }
  }
}



class MinStackNode {

  /** initialize your data structure here. */
  Node top, bottom;
  public MinStackNode() {
    top = new Node(Integer.MIN_VALUE);
    bottom = new Node(Integer.MAX_VALUE);
    top.prev=bottom;
  }
  
  public void push(int x) {
    Node node = new Node(x);
    node.min = Math.min(x, top.prev.min);
    node.prev = top.prev;
    top.prev = node;
  }
  
  public void pop() {
    top.prev = top.prev.prev;
  }
  
  public int top() {
    return top.prev.val;
  }
  
  public int getMin() {
    return top.prev.min;
  }

  class Node {
    int val, min;
    Node prev;
    Node(int v) {
      val = v;
      min = Integer.MAX_VALUE;
    }
  }
}