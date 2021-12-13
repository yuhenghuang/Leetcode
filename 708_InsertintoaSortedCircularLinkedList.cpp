#define CIRCULAR_LINKED_NODE
#define _NONTRIVIAL_SOLUTION_CTOR
#include "utils3.hpp"

class Solution {
  private:
    // avoid memory leak
    vector<Node*> nodes;

  public:
    Node* insert(Node* head, int insertVal) {
      Node* node = nodes.emplace_back(new Node(insertVal));

      if (!head) {
        node->next = node;
        return node;
      }

      Node* p = head;

      // find the largest node
      while (p->next != head && p->next->val >= p->val)
        p = p->next;

      if (insertVal < p->val && insertVal > p->next->val) {
        while (p->next->val < insertVal)
          p = p->next;
      }

      node->next = p->next;
      p->next = node;

      return head;
    }

    ~Solution() {
      for (auto& ptr : nodes)
        delete ptr;
    }
};


int main() {
  UFUNCS(Solution::insert);
  return 0;
}