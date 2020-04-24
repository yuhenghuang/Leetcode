import java.util.HashMap;
import java.util.Map;

class LRUCache_ {
  int cap, size;
  Map<Integer, Node> map;
  Node head, tail;
  public LRUCache_(int capacity) {
    cap = capacity;
    size = 0;
    map = new HashMap<>();
    head = new Node();
    tail = new Node();
    head.next = tail;
    tail.prev = head;
  }
  
  public int get(int key) {
    if (!map.containsKey(key))
      return -1;
    Node n = map.get(key);
    if (n!=head.next) {
      deleteNode(n);
      insertHead(n);
    }
    return n.value;
  }
  
  public void put(int key, int value) {
    Node n;
    if (map.containsKey(key)) {
      n = map.get(key);
      n.value = value;
      if (n!=head.next) {
        deleteNode(n);
        insertHead(n);
      }
    }
    else {
      if (size==cap) {
        n = tail.prev;
        map.remove(n.key);
        deleteNode(n);
        size--;
      }
      n = new Node(key, value);
      map.put(key, n);
      insertHead(n);
      size++;
    }
  }

  void deleteNode(Node n) {
    n.prev.next = n.next;
    n.next.prev = n.prev;
  }

  void insertHead(Node n) {
    n.next = head.next;
    n.prev = head;
    head.next.prev = n;
    head.next = n;
  }

  class Node {
    Node prev, next;
    int key, value;
    Node() {}
    Node(int k, int v) {
      key = k;
      value = v;
    }
  }
}