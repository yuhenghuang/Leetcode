#include <local_leetcode.hpp>

class MedianFinder {
  private:
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;

  public:
    /** initialize your data structure here. */
    MedianFinder() {
      front.push(INT_MIN);
      back.push(INT_MAX);
    }
    
    void addNum(int num) {
      if (front.top() <= num && num <= back.top()) {
        if (front.size() <= back.size())
          front.push(num);
        else
          back.push(num);
      }
      else if (num < front.top()) {
        if (front.size() > back.size()) {
          back.push(front.top());
          front.pop();
        }

        front.push(num);
      }
      else { // num > back.top()
        if (front.size() < back.size()) {
          front.push(back.top());
          back.pop();
        }

        back.push(num);
      }
    }
    
    double findMedian() {
      if (front.size() > back.size())
        return front.top();
      else if (front.size() < back.size())
        return back.top();
      else 
        return static_cast<double>((front.top()) + back.top()) / 2;
    }
};


class MedianFinderList {
  private:
    struct Node {
      Node* prev;
      Node* next;
      int val;
      int freq;

      Node(int _val): prev(nullptr), next(nullptr), val(_val), freq(1) { }
    };

    class Iterator {
      private:
        typedef Iterator self;

        Node* node;
        int pos;

      public:
        Iterator() { }

        Iterator(Node* _node, int _pos): node(_node), pos(_pos) { }

        self& operator++() {
          if (pos < node->freq)
            ++pos;
          else {
            node = node->next;
            pos = 1;
          }

          return *this;
        }

        self& operator--() {
          if (pos > 1)
            --pos;
          else {
            node = node->prev;
            pos = node->freq;
          }

          return *this;
        }

        bool operator==(const self& rhs) const {
          return node == rhs.node && pos == rhs.pos;
        }

        int& operator*() {
          return node->val;
        }
    };

    Node* head;
    
    Iterator p; // left median
    Iterator q; // right median

    // value -> node
    map<int, Node*> m;

  public:
    /** initialize your data structure here. */
    MedianFinderList() {
      head = new Node(INT_MIN);
      Node* tail = new Node(INT_MAX);

      head->next = tail;
      tail->prev = head;

      m[INT_MIN] = head;
      m[INT_MAX] = tail;

      // reassign p and q
      p = Iterator(head, 1);
      q = Iterator(tail, 1);
    }
    
    void addNum(int num) {
      // O(logn)
      auto iter = m.lower_bound(num);
      Node* node = iter->second;

      if (node->val > num) { // add num to linked list before node
        Node* newNode = new Node(num);

        newNode->prev = node->prev;
        newNode->prev->next = newNode;

        newNode->next = node;
        node->prev = newNode;

        // use hint to accelerate the insertion of new element prior to iter
        // time complexity: amortized constant time
        m.emplace_hint(iter, num, newNode);
      }
      else
        ++node->freq;

      if (num < *p) { // num added at left of medians
        if (p == q)
          --p;
        else
          --q;
      }
      else if (num >= *q) { // num added at right of medians
        if (p == q)
          ++q;
        else
          ++p;
      }
      else { // num between medians
        ++p;
        --q;
      }
    }
    
    double findMedian() {
      // O(1)
      return static_cast<double>(*p + *q) / 2;
    }

    ~MedianFinderList() { ll::destroy(head); }
};


int main() {
  EXECX(
    CTOR(),
    &MedianFinder::addNum,
    &MedianFinder::findMedian
  );

  EXECX(
    CTOR(),
    &MedianFinderList::addNum,
    &MedianFinderList::findMedian
  );
  return 0;
}