class Node {
  private:
    Node *prev, *next;
    int val;
  public:
    Node() {}
    Node(int v): val(v) {}
    int getVal() { return val; }
    Node *getPrev() { return prev; }
    Node *getNext() { return next; }
    void setPrev(Node *n) { prev = n; }
    void setNext(Node *n) { next = n; }
    void insertNext(Node *n) {
      n->prev = this;
      n->next = next;
      next->prev = n;
      next = n;
    }
    void insertPrev(Node *n) {
      n->prev = prev;
      n->next = this;
      prev->next = n;
      prev = n;
    }
    void deleteSelf() {
      this->prev->next = this->next;
      this->next->prev = this->prev;
    }
};

class MyLinkedList {
  private:
    int size;
    Node* front, *rear;
  public:
    /** Initialize your data structure here. */
    MyLinkedList() {
      front = new Node();
      rear = new Node();
      front->setNext(rear);
      rear->setPrev(front);
      size=0;
    }

    ~MyLinkedList() {
      Node *p = front, *q = front->getNext();
      while (q==rear) {
        delete p;
        p = q;
        q = q->getNext();
      }
      delete p, q;
    }

    Node* getPtr(int idx) {
      Node* ptr;
      if (idx<size/2) {
        ptr = front->getNext();
        while (idx-->0) {
          ptr = ptr->getNext();
        }
      }
      else {
        idx = size - idx;
        ptr = rear;
        while (idx-->0) {
          ptr = ptr->getPrev();
        }
      }
      return ptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
      if (index<0 || index>=size) return -1;
      return getPtr(index)->getVal();
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      Node* node = new Node(val);
      front->insertNext(node);
      size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      Node* node = new Node(val);
      rear->insertPrev(node);
      size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
      if (index<0 || index>size) return;
      Node *p = getPtr(index);
      Node *q = new Node(val);
      p->insertPrev(q);
      size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      if (index<0 || index>=size) return;
      Node *node = getPtr(index);
      node->deleteSelf();
      size--;
      delete node;
    }
};