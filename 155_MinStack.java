class MinStackFast {
  ListNode head;
  /** initialize your data structure here. */
  public MinStackFast() {
    head = new ListNode(Integer.MAX_VALUE, Integer.MAX_VALUE);
    head.prev = head;
  }
  
  public void push(int x) {
    ListNode node = new ListNode(x, Math.min(head.prev.min, x));
    node.prev = head.prev;
    head.prev = node;

  }
  
  public void pop() {
    head.prev = head.prev.prev;
  }
  
  public int top() {
    return head.prev.val;
  }
  
  public int getMin() {
    return head.prev.min;
  }

  class ListNode {
    int val, min;
    ListNode prev;
    ListNode(int v, int m) {
      val = v;
      min = m;
    }
  }
}