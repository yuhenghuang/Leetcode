#include "DataStructure.h"
#include <unordered_map>

using namespace std;

class Solution {
  private:
    unordered_map<Node*, Node*> dict;

    void cloneGraph(Node* node, Node* clone) {
      dict[node] = clone;
      for (Node* n : node->neighbors) {
        if (dict[n])
          clone->neighbors.push_back(dict[n]);
        else {
          Node* c = new Node(n->val);
          clone->neighbors.push_back(c);
          cloneGraph(n, c);
        }
      }
    }
  public:
    Node* cloneGraph(Node* node) {
      if (!node) return node;

      Node* clone = new Node(node->val);

      cloneGraph(node, clone);
      return clone;
    }
};

