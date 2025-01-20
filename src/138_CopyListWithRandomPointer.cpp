/*
#define RANDOM_POINTER
#include "DataStructure.h"

#include <unordered_map>
#include <vector>

using namespace std;
*/

#define RANDOM_LIST_NODE
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*, int> node2idx;

      int i = 0;
      Node* node = head;
      while (node) {
        node2idx[node] = i++;
        node = node->next;
      }

      node2idx[nullptr] = i;

      int n = i;
      vector<Node*> vec(n+1);
      vec[n] = nullptr;

      node = head;
      for (i=0; i<n; ++i) {
        vec[i] = new Node(node->val);
        node = node->next;
      }

      node = head;
      for (i=0 ;i<n; ++i) {
        vec[i]->next = vec[i+1];
        vec[i]->random = vec[node2idx[node->random]];
        node = node->next;
      }

      return vec[0];
    }

    Node* copyRandomListO1(Node* head) {
      if (!head)
        return nullptr;

      unordered_map<Node*, Node*> m;
      m[nullptr] = nullptr;

      Node* res = new Node(head->val);
      m[head] = res;

      Node* p = head->next;
      Node* q = res;
      while (p) {
        q->next = new Node(p->val);
        m[p] = q->next;

        p = p->next;
        q = q->next;
      }

      p = head;
      q = res;
      while (p) {
        q->random = m[p->random];

        p = p->next;
        q = q->next;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::copyRandomList);
  EXECS(Solution::copyRandomListO1);
  return 0;
}