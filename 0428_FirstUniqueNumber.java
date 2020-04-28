import java.util.HashMap;
import java.util.Map;

class FirstUnique {
  public static void main(String[] args) {
    int nums[] = LeetcodeUtil.arrayIntParser("[2,3,5]");
    FirstUnique obj = new FirstUnique(nums);
    System.out.println(obj.showFirstUnique());
    obj.add(5);
    System.out.println(obj.showFirstUnique());
    obj.add(2);
    System.out.println(obj.showFirstUnique());
    obj.add(3);
    System.out.println(obj.showFirstUnique());
  }
  Node head, tail;
  Map<Integer, Node> map;
  public FirstUnique(int[] nums) {
    head = new Node();
    tail = new Node();
    head.next = tail;
    tail.prev= head;
    map = new HashMap<>();
    for (int n : nums) 
      add(n);
  }
  
  public int showFirstUnique() {
    if (head.next!=tail) 
      return head.next.key;
    else 
      return -1;
  }

  void insertPrevTail(Node n) {
    n.prev = tail.prev;
    n.next = tail;
    tail.prev.next = n;
    tail.prev = n;
  }
  
  public void add(int value) {
    Node n;
    if (!map.containsKey(value)) {
      n = new Node(value);
      insertPrevTail(n);
      map.put(value, n);
    }
    else {
      n = map.get(value);
      if (n.count==1) {
        n.prev.next = n.next;
        n.next.prev = n.prev;
      }
      n.count++;
    }
  }

  class Node {
    Node prev, next;
    int key, count;
    Node() {}
    Node(int k) {
      key = k;
      count = 1;
    }
  }
}