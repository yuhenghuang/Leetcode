#define RANDOM_POINTER
#include "DataStructure.h"

#include <unordered_map>
#include <vector>

using namespace std;

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
};