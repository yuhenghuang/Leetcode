import java.util.Stack;

public class IntersectionLinkedList {
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    Stack<ListNode> A = new Stack<>();
    Stack<ListNode> B = new Stack<>();
    while (headA!=null) {
      A.push(headA);
      headA=headA.next;
    }

    while (headB!=null) {
      B.push(headB);
      headB=headB.next;
    }

    while (!A.isEmpty() && !B.isEmpty()) {
      headA = A.pop();
      headB = B.pop();
      if (headA!=headB)
        return headA.next;
    }
    return A.isEmpty()?B.pop().next:A.pop().next;
  }
}