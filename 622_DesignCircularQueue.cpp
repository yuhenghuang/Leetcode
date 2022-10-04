#include <local_leetcode.hpp>

class MyCircularQueue {
  private:
    int begin, end, size;
    vector<int> vec;
  public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): begin(0), end(0), size(k+1) {
      vec.resize(k+1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
      if (isFull()) return false;

      vec[end] = value;
      end = (end+1)%size;

      return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
      if (isEmpty()) return false;

      begin = (begin+1)%size;

      return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
      return isEmpty() ? -1 : vec[begin];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
      return isEmpty() ? -1 : vec[(end+size-1)%size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
      return begin == end;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      return (end+1)%size == begin;
    }
};


// [begin, end) -> [front, rear + 1)
class CircularQueue {
  private:
    struct Node {
      int val;
      Node* next;
    };

    Node* root;

  protected:
    Node* begin;
    Node* end;

    int rear;

  public:
    CircularQueue(int k) {
      root = new Node[k + 1];

      root[k].next = root;
      for (int i = 0; i < k; ++i)
        root[i].next = &root[i+1];

      begin = root;
      end = root;
    }

    ~CircularQueue() { delete[] root;}
    
    bool enQueue(int value) {
      if (!isFull()) {
        
        end->val = rear = value;
        end = end->next;

        return true;
      }

      return false;
    }
    
    bool deQueue() {
      if (!isEmpty()) {
        begin = begin->next;

        return true;
      }

      return false;
    }
    
    int Front() {
      return isEmpty() ? -1 : begin->val;
    }
    
    int Rear() {
      return isEmpty() ? -1 : rear;
    }
    
    bool isEmpty() {
      return begin == end;
    }
    
    bool isFull() {
      return end->next == begin;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &MyCircularQueue::deQueue,
    &MyCircularQueue::enQueue,
    &MyCircularQueue::Front,
    &MyCircularQueue::Rear,
    &MyCircularQueue::isEmpty,
    &MyCircularQueue::isFull
  );

  EXECX(
    CTOR(int),
    &CircularQueue::deQueue,
    &CircularQueue::enQueue,
    &CircularQueue::Front,
    &CircularQueue::Rear,
    &CircularQueue::isEmpty,
    &CircularQueue::isFull
  );

  return 0;
}
