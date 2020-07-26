class AddTwoNumbers {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    return recursive(l1, l2, 0);
  }

  ListNode recursive(ListNode p, ListNode q, int res) {
    if (p==null && q==null && res==0) return null;
    res += (p==null?0:p.val) + (q==null?0:q.val);
    ListNode node = new ListNode(res % 10);
    node.next = recursive(p==null?p:p.next, q==null?q:q.next, res/10);
    return node;
  }
}