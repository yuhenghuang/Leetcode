public class OddEvenLink {
  public ListNode oddEvenList(ListNode head) {
    ListNode oddHead=head, evenHead=head.next;
    ListNode oddTail=recursive(oddHead, evenHead);
    oddTail.next=evenHead;
    return head;
  }

  public ListNode recursive(ListNode oddP, ListNode evenP) {
    if (evenP==null) return oddP;
    ListNode evenNext=null;
    if (evenP.next!=null) {
      oddP.next=evenP.next;
      oddP=oddP.next;
    }
    else oddP.next=null;

    if (oddP.next!=null) {
      evenNext=oddP.next;
    }
    evenP.next=evenNext;
    return recursive(oddP, evenNext);
  }
}