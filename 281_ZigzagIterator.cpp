#include <local_leetcode.hpp>

class CyclicIterator {
  private:
    typedef vector<int>::const_iterator iter_t;

    struct Node {
      Node* next;

      iter_t iter;
      iter_t end;

      Node(): next(nullptr) { }
      Node(const vector<int>& v): iter(v.begin()), end(v.end()), next(nullptr) { }
    };

    Node* sentinel;
    Node* node;

    // return inserted node
    Node* insert_after(Node* curr, Node* node) {
      node->next = curr->next;
      curr->next = node;

      return node;
    }

    void remove_empty() {
      // enter while loop if empty or sentinel comes next
      while (node->next != node && node->next->iter == node->next->end) {
        if (node->next != sentinel) {
          Node* tmp = node->next;
          node->next = tmp->next;
          delete tmp;
        }
        else
          node = node->next; // skip sentinel
      }
    }

  public:
    template <
      typename... Tp,
      typename = typename std::enable_if<
        ll::all<
          std::is_convertible<Tp&&, const vector<int>&>::value ...
        >::value
      >::type
    >
    CyclicIterator(Tp&&... vs) {
      sentinel = new Node();
      sentinel->next = sentinel;

      node = sentinel;
      (
        (node = insert_after(node, new Node(vs))),
        ...
      );

      node = sentinel;
    }

    int next() {
      // remove_empty();
      int res = *(node->next->iter++);
      node = node->next;
      return res;
    }

    bool hasNext() {
      remove_empty();
      return sentinel->next != sentinel;
    }

    ~CyclicIterator() { delete sentinel; }
};


class Solution {
  public:
    vector<int> iterate2(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
      vector<int> res;

      CyclicIterator iter(v1, v2);
      while (iter.hasNext()) 
        res.push_back(iter.next());

      return res;
    }

    vector<int> iterate3(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
      vector<int> res;

      CyclicIterator iter(v1, v2, v3);
      while (iter.hasNext()) 
        res.push_back(iter.next());

      return res;
    }
};


int main() {
  EXECS(Solution::iterate2);
  EXECS(Solution::iterate3);
  return 0;
}