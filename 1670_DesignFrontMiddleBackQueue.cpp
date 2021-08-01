#include "utils3.hpp"

class FrontMiddleBackQueue {
  private:
    deque<int> fq, bq;

    void front_to_back() {
      bq.push_front(fq.back());
      fq.pop_back();
    }

    void back_to_front() {
      fq.push_back(bq.front());
      bq.pop_front();
    }

  public:
    FrontMiddleBackQueue() { }
    
    void pushFront(int val) {
      if (bq.empty()) {
        bq.push_front(val);
        return;
      }

      if (fq.size() == bq.size())
        front_to_back();

      fq.push_front(val);
    }
    
    void pushMiddle(int val) {
      if (fq.size() == bq.size())
        bq.push_front(val);
      else
        fq.push_back(val);
    }
    
    void pushBack(int val) {
      if (fq.size() < bq.size())
        back_to_front();

      bq.push_back(val);
    }
    
    int popFront() {
      if (bq.empty())
        return -1;

      if (fq.size() < bq.size())
        back_to_front();

      int res = fq.front();
      fq.pop_front();
      return res;
    }
    
    int popMiddle() {
      if (bq.empty())
        return -1;

      int res;
      if (fq.size() == bq.size()) {
        res = fq.back();
        fq.pop_back();
      }
      else {
        res = bq.front();
        bq.pop_front();
      }

      return res;
    }
    
    int popBack() {
      if (bq.empty())
        return -1;

      if (fq.size() == bq.size())
        front_to_back();

      int res = bq.back();
      bq.pop_back();
      return res;
    }
};


struct Node {
  int val;
  Node* prev;
  Node* next;

  Node(int _val = -1): val(_val), prev(nullptr), next(nullptr) { }

  int erase_node(Node* node) {
    if (!node)
      return -1;

    int tmp = node->val;

    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;
    delete node;

    return tmp;
  }

  int erase_after() { return erase_node(next); }
  int erase_before() { return erase_node(prev); }

  void insert_after(int _val) {
    Node* node = new Node(_val);
    node->prev = this;
    node->next = next;

    if (next)
      next->prev = node;

    next = node;
  }

  void insert_before(int _val) {
    Node* node = new Node(_val);
    node->prev = prev;
    node->next = this;

    if (prev)
      prev->next = node;

    prev = node;
  }
};


class FrontMiddleBackQueueList {
  private:
    size_t size;
    Node* head;
    Node* tail;
    Node* mid;

  public:
    FrontMiddleBackQueueList(): size(0) {
      head = new Node();
      tail = new Node();
      head->next = tail;
      tail->prev = head;
      mid = head;
    }
    
    void pushFront(int val) {
      head->insert_after(val);

      if (size == 0)
        mid = head->next;
      else if (size % 2 == 1)
        mid = mid->prev;

      ++size;
    }
    
    void pushMiddle(int val) {
      if (size++ % 2 == 0) {
        mid->insert_after(val);
        mid = mid->next;
      }
      else {
        mid->insert_before(val);
        mid = mid->prev;
      }
    }
    
    void pushBack(int val) {
      tail->insert_before(val);

      if (size++ % 2 == 0)
        mid = mid->next;
    }
    
    int popFront() {
      if (size == 0)
        return -1;

      if (size == 1) 
        mid = head;
      else if (size % 2 == 0) 
        mid = mid->next;

      --size;
      return head->erase_after();
    }
    
    int popMiddle() {
      if (size == 0)
        return -1;

      if (size-- % 2 == 0) {
        mid = mid->next;
        return mid->erase_before();
      }
      else {
        mid = mid->prev;
        return mid->erase_after();
      }
    }
    
    int popBack() {
      if (size == 0)
        return -1;

      if (size-- % 2 == 1)
        mid = mid->prev;

      return tail->erase_before();
    }

    ~FrontMiddleBackQueueList() { utils3::destroy(head); }
};


int main() {
  UFUNCX(
    CTOR(),
    &FrontMiddleBackQueue::pushFront,
    &FrontMiddleBackQueue::pushMiddle,
    &FrontMiddleBackQueue::pushBack,
    &FrontMiddleBackQueue::popFront,
    &FrontMiddleBackQueue::popMiddle,
    &FrontMiddleBackQueue::popBack
  );
  UFUNCX(
    CTOR(),
    &FrontMiddleBackQueueList::pushFront,
    &FrontMiddleBackQueueList::pushMiddle,
    &FrontMiddleBackQueueList::pushBack,
    &FrontMiddleBackQueueList::popFront,
    &FrontMiddleBackQueueList::popMiddle,
    &FrontMiddleBackQueueList::popBack
  );
  return 0;
}