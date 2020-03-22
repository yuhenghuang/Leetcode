import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.ArrayDeque;

public class LRUCache {
  int cap;
  Map<Integer, Node> map;
  Node first, last;
  public LRUCache(int capacity) {
    cap = capacity+2;
    map = new HashMap<>();
    first = new Node(0, 0);
    last = new Node(-1, -1);
    //map.put(0, first);
    //map.put(-1, last);
  }
  
  public int get(int key) {
    if (!map.containsKey(key)) return -1;
    Node node = map.get(key);
    toLast(node);
    return node.val;
  }

  private void toLast(Node node) {
    if (node.next!=last) {
      node.next.prev = node.prev;
      node.prev.next = node.next;

      node.prev=last.prev;
      node.next=last;

      last.prev.next=node;
      last.prev=node;
    }
  }
  
  public void put(int key, int value) {
    Node node;
    if (map.isEmpty()){
      node = new Node(key, value);
      //initialize by first input
      first.next=node;
      node.prev=first;
      node.next=last;
      last.prev=node;
      map.put(key, node);
    }

    if (map.containsKey(key)) {
      node = map.get(key);
      node.val = value;
      toLast(node);
    }
    else {
      if (map.size()==cap) {
        node=first.next;
        first.next=node.next;
        node.next.prev=first;
        map.remove(node.key);
      }
      node = new Node(key, value);
      last.prev.next=node;
      node.prev=last.prev;
      node.next=last;
      last.prev=node;
      map.put(key, node);
      }
    if (map.size()>cap) {
      Node n = first;
      while (n!=null) {
        System.out.print(n.key+" ");
        n=n.next;
      }
      System.out.println("");
    }
  }

  class Node {
    int key, val;
    Node prev, next;
    Node(int k, int v) {
      key = k;
      val = v;
    }
  }
}


class LRUCacheSlow {
  int cap;
  Map<Integer, Integer> map;
  Queue<Integer> queue;
  public LRUCacheSlow(int capacity) {
    cap = capacity;
    map = new HashMap<>();
    queue = new ArrayDeque<>();
  }
  
  public int get(int key) {
    if (map.containsKey(key)) {
      queue.remove(key);
      queue.add(key);
    }
    return map.getOrDefault(key, -1);
  }
  
  public void put(int key, int value) {
    if (map.size()==cap && !map.containsKey(key)) {
      map.remove(queue.poll());
    }
    else {
      queue.remove(key);
    }
    map.put(key, value);
    queue.add(key);
  }
}