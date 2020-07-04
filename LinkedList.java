public class LinkedList<T> {
  public static void main(String[] args) {
    LinkedList<String> list = new LinkedList<>();
    list.insertFront("aaa");
    list.insertFront("bbb");
    list.insertFront("ccc");
    System.out.println(list.size());
    list.printValues();
  }
  class Node {
    Node next;
    T val;
    Node() {}
    Node(T v) {
      val = v;
    }
  
    void insertNext(T v) {
      Node node = new Node(v);
      if (next!=null)
        node.next = next.next;
      next = node;
    }
  
    void deleteNext() {
      if (next!=null)
        next = next.next;
    }
  }

  private Node head;
  private Node prev, curr;
  private int size, index;
  LinkedList() {
    head = new Node();
    prev = head;
    size = 0;
    index = -1;
  }

  LinkedList(T v) {
    head = new Node();
    head.next = new Node(v);
    prev = head;
    curr = head.next;

    size = 1;
    index = 0;
  }

  T getValue() {
    return curr==null ? null : curr.val;
  }

  int size() {
    return size;
  }

  int currentPosition() {
    return index;
  }

  void resetIndex() {
    prev = head;
    if (size==0) {
      index = -1;
      curr = null;
    }
    else {
      index = 0;
      curr = head.next;
    }
  }

  void forward(int x) {
    if (index+x<size) {
      index += x;
      while (x-->0) {
        prev = curr;
        curr = curr.next;
      }
    }
  }

  void jumpTo(int x) {
    if (x<0 || x>=size) return;
    if (x<index) 
      resetIndex();
    forward(x-index);
  }

  void insertFront(T v) {
    head.insertNext(v);
    if (size==0) 
      curr = head.next;
    else if (index==0) 
      prev = head.next;
      
    ++index;
    ++size;
  }

  void deleteFront() {
    if (size==0) return;
    else if (index==0) {
      curr = curr.next;
      head.deleteNext();
      if (curr==null) index=-1;
    }
    else {
      if (index==1)
        prev = head;
      --index;
    }
    --size;
  }

  void insertAfter(T v) {
    if (curr==null) return;
    curr.insertNext(v);
    ++size;
  }

  void insertBefore(T v) {
    if (prev==head)
      insertFront(v);
    else {
      prev.insertNext(v);
      prev = prev.next;

      ++index;
      ++size;
    }
  }

  void deleteAfter() {
    if (curr==null || curr.next==null) return;
    curr.deleteNext();
    --size;
  }

  void deleteCurr() {
    if (curr==null) return;
    prev.deleteNext();
    curr = prev.next;
    --size;
  }

  void printValues() {
    Node node = head.next;
    while (node!=null) {
      System.out.print(node.val+"\t");
      node = node.next;
    }
    System.out.println();
  }
}