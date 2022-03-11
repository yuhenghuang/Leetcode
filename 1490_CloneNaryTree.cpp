#define NARY_TREE_NODE
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  private:
    Node* cloneTreeImpl(Node* root) {
      Node* node = new Node(root->val);

      for (Node*& child : root->children)
        node->children.push_back(cloneTreeImpl(child));

      return node;
    }

  public:
    Node* cloneTree(Node* root) {
      if (!root)
        return nullptr;

      return cloneTreeImpl(root);
    }
};


int main() {
  EXECS(Solution::cloneTree);
  return 0;
}