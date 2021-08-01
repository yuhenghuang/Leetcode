#include "utils3.hpp"

class MyCircularDeque {
  private:
    int size;
    const int max_size;
    vector<int> data;

    // ++, --
    int begin, end;

  public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): begin(0), end(0), size(0), max_size(k), data(k) { }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
      if (isFull())
        return false;

      begin = (begin + 1) % max_size;
      data[begin] = value;

      ++size;

      return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
      if (isFull())
        return false;

      data[end] = value;
      end = (end - 1 + max_size) % max_size;
      ++size;

      return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
      if (isEmpty())
        return false;

      begin = (begin - 1 + max_size) % max_size;
      --size;
      return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
      if (isEmpty())
        return false;

      end = (end + 1) % max_size;
      --size;
      return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
      return isEmpty() ? -1 : data[begin];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
      return isEmpty() ? -1 : data[(end + 1) % max_size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
      return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
      return size == max_size;
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &MyCircularDeque::insertFront,
    &MyCircularDeque::insertLast,
    &MyCircularDeque::deleteFront,
    &MyCircularDeque::deleteLast,
    &MyCircularDeque::getFront,
    &MyCircularDeque::getRear,
    &MyCircularDeque::isEmpty,
    &MyCircularDeque::isFull
  );
  return 0;
}