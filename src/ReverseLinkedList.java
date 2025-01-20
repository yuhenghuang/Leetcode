public class ReverseLinkedList {
  public ListNode reverseList(ListNode head) {
    //ListNode p = null;
    return recursive(null, head);
  }

  public ListNode recursive(ListNode a, ListNode b) {
    if (b==null) return a;
    ListNode c = b.next;
    b.next=a;
    return recursive(b, c);
  }


  public ListNode reverseList_iter(ListNode head) {
    if (head==null) return head;
    ListNode p1=null, p2=head.next;
    while (head!=null) {
      head.next=p1;
      p1=head;
      head=p2;
      if (p2!=null) p2=p2.next;
    }
    return p1;
  }
}