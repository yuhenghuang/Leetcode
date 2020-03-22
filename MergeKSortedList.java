import java.util.*;

public class MergeKSortedList {
  public ListNode mergeKLists(ListNode[] lists) {
    Queue<ListNode> heap = new PriorityQueue<>(
      (node1, node2) -> node1.val - node2.val
    );

    for (ListNode node : lists)
      if (node!=null)
        heap.offer(node);

    ListNode head = new ListNode(0);
    ListNode prev = head;
    while (!heap.isEmpty()) {
      ListNode next = heap.poll();
      prev.next = next;
      prev = next;
      if (next.next!=null)
        heap.offer(next.next);
    }
    return head.next;
  }
}