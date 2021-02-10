#include <vector>

using namespace std;

class Iterator {
  private:
    struct Data;
    Data* data;
  public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
  private:
    int cacheNum;
    bool cacheHasNext;

  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.

      cacheHasNext = Iterator::hasNext();
      if (cacheHasNext)
        cacheNum = Iterator::next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
      return cacheHasNext;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
      int tmp = cacheNum;
      cacheHasNext = Iterator::hasNext();
      if (cacheHasNext)
        cacheNum = Iterator::next();
      return tmp;
    }
    
    bool hasNext() const {
      return cacheHasNext;
    }
};