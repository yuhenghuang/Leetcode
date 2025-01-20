class MedianofLinkedList {
  ListNode h;
  public ListNode middleNode(ListNode head) {
    // circle
    // failed
    // hahaha
    h = head;
    ListNode p = head, q = head;
    do {
      p=forward(p);
      q=forward(forward(q));
    } while (p!=q);
    return p;
  }
  private ListNode forward(ListNode p) {
    return p.next==null?h:p.next;
  }

  public ListNode middleNodeMid(ListNode head) {
    int len=0;
    ListNode p = head;
    while (p.next!=null) {
      p=p.next;
      len++;
    }

    int mid = len / 2 + len % 2;
    while (mid-->0) {
      head = head.next;
    }
    return head;
  }
}