import java.util.*;

public class LFUCache {
  public static void main(String[] args) {
    LFUCache cache = new LFUCache(3);
    cache.put(10, 3);
    cache.put(3, 11);
    cache.put(6, 11);
    cache.put(10, 5);
    //System.out.println(cache.get(0));
  }
  int size, cap;
  Map<Integer, ListNode> freq;
  Map<Integer, ListNode> dict;
  ListNode head, tail;
  public LFUCache(int capacity) {
    size = 0;
    cap = capacity;
    freq = new HashMap<>();
    dict = new HashMap<>();

    head = new ListNode(-1, -1, 0);
    tail = new ListNode(Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE);
    head.next = tail;
    tail.prev = head;
  }
  
  public int get(int key) {
    ListNode node = dict.getOrDefault(key, head);
    if (node!=head) update(node);
    return node.val;
  }
  
  public void put(int key, int value) {
    ListNode node;
    if (dict.containsKey(key)) {
      node = dict.get(key);
      node.val = value;
      update(node);
    }
    else if (cap>0){
      node = new ListNode(key, value, 1);
      dict.put(key, node);
      if (size==cap) {
        ListNode lfnode = head.next;
        dict.remove(lfnode.key);
        if (lfnode.next.freq>lfnode.freq)
          if (lfnode.prev.freq<lfnode.freq)
            freq.remove(lfnode.freq);
          else
            freq.put(lfnode.freq, lfnode.prev);
        head.next = lfnode.next;
        lfnode.next.prev = head;
        size--;
      }
      ListNode target = freq.getOrDefault(1, head);
      node.next = target.next;
      node.prev = target;
      node.next.prev = node;
      target.next = node;
      freq.put(1, node);
      size++;
    }
  }

  private void update(ListNode node) {
    ListNode target;
    if (!freq.containsKey(node.freq+1)) {
      target = freq.get(node.freq);
      if (target!=node) 
        movenode(node, target);
      else if (target.prev.freq<target.freq)
        freq.remove(target.freq);
      else 
        freq.put(node.freq, node.prev);
    }
    else {
      target = freq.get(node.freq+1);
      if (node.next.freq>node.freq)
        if (node.prev.freq<node.freq)
          freq.remove(node.freq);
        else
          freq.put(node.freq, node.prev);
      movenode(node, target);
    }
    freq.put(++node.freq, node);
  }

  private void movenode(ListNode node, ListNode target) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
    
    node.prev=target;
    node.next=target.next;
    target.next=node;
    node.next.prev=node;
  }

  class ListNode {
    int key, val, freq;
    ListNode prev, next;
    ListNode (int k, int v, int f) {
      key = k;
      val = v;
      freq = f;
    }
  }
}