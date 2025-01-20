public class ReverseLinkedListII {
  public ListNode reverseBetween(ListNode head, int m, int n) {
    ListNode p1=new ListNode(-1), p2=head;
    ListNode prev=p1, next=null, p3;
    p1.next=head;
    for (int i=1; i<=n; ++i) {
      if (i<=m) {
        p1=p1.next;
        p2=p2.next;
        if (i==m-1) prev=p1;
      }
      else {
        p3 = p2.next;
        p2.next=p1;
        p1=p2;
        p2=p3;
        if (i==n) next=p3;
      }
    }
    prev.next.next=next;
    prev.next=p1;
    return m==1?prev.next:head;
  }
}