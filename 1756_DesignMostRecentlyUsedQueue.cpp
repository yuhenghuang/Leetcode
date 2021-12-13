#include "utils3.hpp"

/*
  time complexity: 
    overall:
      between O(sqrt(n)) and O(n), but closer to O(sqrt(n))
    best: O(sqrt(n) + sqrt(n))
      sqrt(n) to find the corresponding node
      sqrt(n) to remove the element from the node
    worst: O(n)
      close n to find the corresponding node
      close to 1 to remove the element from the node
    always 1 to push back
  
  space complexity:
    overall:
      between O(n * sqrt(n)) and O(n), but closer to O(n * sqrt(n))
    best: O(n)
      sqrt(n) nodes * sqrt(n) elements(space) in each node
    worst: O(n * sqrt(n))
      close to n nodes * sqrt(n) elements(space) in each node

  since the last nodes are always filled with sqrt(n) elements,
  the worst case cannot be reached
*/


class MRUQueueCustom {
  private:
    class Node {
      private:
        int* data;
        // current size
        size_t s;

      public:
        Node* next;

        Node(): next(nullptr), data(nullptr) { }

        // chunk_size is shared within the outer class
        // no need to save it in each node
        Node(size_t chunk_size): next(nullptr), s(0) {
          // allocate heap memory
          data = new int[chunk_size];
        }

        // push val to back
        void push_back(int val) { data[s++] = val; }

        // erase element at index i
        int erase(size_t i) {
          int val = data[i];

          for (--s; i < s; ++i)
            data[i] = data[i+1];

          return val;
        }

        bool empty() const { return s == 0; }

        size_t size() const { return s; }

        ~Node() {
          if (data)
            delete[] data;
        }
    };

    Node* head;
    Node* tail;

    size_t chunk_size;

  public:
    MRUQueueCustom(int n) {
      chunk_size = 1;
      while (chunk_size * chunk_size < n)
        ++chunk_size;

      head = new Node();
      Node* curr = head;


      for (int i = 0; i < n; ++i) {
        if (i % chunk_size == 0) {
          if (curr->next == nullptr)
            curr->next = new Node(chunk_size);

          curr = curr->next;
        }

        curr->push_back(i+1);
      }

      tail = curr;
    }

    int fetch(int k) {
      // best sqrt(n) to find the node
      Node* prev = head;
      while (k > prev->next->size()) {
        k -= prev->next->size();
        prev = prev->next;
      }

      Node* curr = prev->next;

      // sqrt(n) to erase the element in the node
      int val = curr->erase(k - 1);

      // move curr after tail once it becomes empty
      // avoid unnecessary new / delete operations
      // works similar to a memory pool??
      if (curr->empty() && curr != tail) {
        // remove curr
        prev->next = curr->next;

        // add curr after tail
        curr->next = tail->next;
        tail->next = curr;
      }

      // move tail to next if it's full
      if (tail->size() == chunk_size) {
        if (tail->next == nullptr)
          tail->next = new Node(chunk_size);

        tail = tail->next;
      }

      tail->push_back(val);
      return val;
    }

    ~MRUQueueCustom() { utils3::destroy(head); }
};



class MRUQueue {
  private:
    struct Node {
      Node* next;
      vector<int> data;

      Node(): next(nullptr) { }
    };

    // (head, tail] contain data
    Node* head;
    Node* tail;

    size_t chunk_size;

  public:
    MRUQueue(int n) {
      chunk_size = 1;
      while (chunk_size * chunk_size < n)
        ++chunk_size;

      head = new Node();
      Node* curr = head;

      for (int i = 0; i < n; ++i) {
        if (i % chunk_size == 0) {
          if (curr->next == nullptr)
            curr->next = new Node();

          curr = curr->next;
        }

        curr->data.push_back(i+1);
      }

      tail = curr;
    }

    int fetch(int k) {
      Node* prev = head;
      while (k > prev->next->data.size()) {
        k -= prev->next->data.size();
        prev = prev->next;
      }

      Node* curr = prev->next;
      int val = *curr->data.erase(curr->data.begin() + (k - 1));

      // move curr after tail if it becomes empty
      // avoid unnecessary new / delete operations
      if (curr->data.empty() && curr != tail) {
        prev->next = curr->next;

        curr->next = tail->next;
        tail->next = curr;
      }

      // move tail to next
      if (tail->data.size() == chunk_size) {
        if (tail->next == nullptr)
          tail->next = new Node();

        tail = tail->next;
      }

      tail->data.push_back(val);
      return val;
    }

    ~MRUQueue() { utils3::destroy(head); }
};


int main() {
  UFUNCX(
    CTOR(int),
    &MRUQueue::fetch
  );
  UFUNCX(
    CTOR(int),
    &MRUQueueCustom::fetch
  );
  return 0;
}