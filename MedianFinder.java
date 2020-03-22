import java.util.Map;
import java.util.HashMap;

public class MedianFinder {
  int size;
  int[] median;
  ListNode head, tail;
  Map<Integer, ListNode> map;
  /** initialize your data structure here. */
  public MedianFinder() {
    size=0;
    map = new HashMap<>();
    head = new ListNode(Integer.MIN_VALUE, 0);
    tail = new ListNode(Integer.MAX_VALUE, 0);
    head.next = tail;
    tail.prev = head;
    median = new int[] {head.val, 0, tail.val, 0};
  }
  
  public void addNum(int num) {
    if (map.containsKey(num)) {
      ListNode node = map.get(num);
      node.count++;
    }
    else {
      ListNode node = head;
      while (node.next.val<num) node=node.next;
      ListNode newNode = new ListNode(num, 1);
      newNode.next=node.next;
      newNode.prev=node;
      node.next.prev=newNode;
      node.next=newNode;
      map.put(num, newNode);
    }
    updateMedian(num);
    for (int i:median) System.out.print(i+"\t");
    System.out.println("");
  }

  private void updateMedian(int num) {
    if (num>=median[2] && median[0]!=median[2]) prevornot(false);
    else if (num<=median[0]) {
      if (num==median[0] && median[0]!=median[2]) median[1]++;
      prevornot(true);
    }
    else {
      median[0]=num;
      median[1]=1;
      median[2]=num;
      median[3]=1;
    }

    if (median[1]<1) {
      ListNode node = map.get(median[0]).prev;
      median[0]=node.val;
      median[1]=node.count;
    }
    else if (median[1]>map.get(median[0]).count) {
      median[0]=map.get(median[0]).next.val;
      median[1]=1;
    }

    if (median[3]<1) {
      ListNode node = map.get(median[2]).prev;
      median[2]=node.val;
      median[3]=node.count;
    }
    else if (median[3]>map.get(median[2]).count) {
      median[2]=map.get(median[2]).next.val;
      median[3]=1;
    }
    size++;
  }

  private void prevornot(boolean prev) {
    if (median[0]==median[2] && median[1]==median[3]) {
      if (prev) median[1]--;
      else median[3]++;
    }
    else {
      if (prev) median[3]--;
      else median[1]++;
    }
  }
  
  public double findMedian() {
    return (double) (median[0]+median[2])/2;
  }

  class ListNode {
    ListNode prev, next;
    int val, count;

    ListNode(int v, int c) {
      val = v;
      count = c;
    }
  }
}



class MedianFinderSlow {
  int size;
  ListNode head, tail;
  Map<Integer, ListNode> map;
  /** initialize your data structure here. */
  public MedianFinderSlow() {
    size=0;
    map = new HashMap<>();
    head = new ListNode(Integer.MIN_VALUE, 0);
    tail = new ListNode(Integer.MAX_VALUE, 0);
    head.next = tail;
  }
  
  public void addNum(int num) {
    if (map.containsKey(num)) {
      ListNode node = map.get(num);
      node.count++;
    }
    else {
      ListNode node = head;
      while (node.next.val<num) node=node.next;
      ListNode newNode = new ListNode(num, 1);
      newNode.next=node.next;
      node.next=newNode;
      map.put(num, newNode);
    }
    size++;
  }
  
  public double findMedian() {
    int cumSum=0, target=size/2;
    ListNode node = head;
    while (node.next!=tail && cumSum<target) {
      cumSum+=node.next.count;
      node=node.next;
    }
    if (target % 2==0 || cumSum!=target) {
      return (double) node.val;
    }
    else {
      return (double) (node.val+node.next.val)/2;
    }
  }

  class ListNode {
    ListNode next;
    int val, count;

    ListNode(int v, int c) {
      val = v;
      count = c;
    }
  }
}