#include <vector>

using namespace std;

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
