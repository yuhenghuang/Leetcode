#define RANDOM_TREE_NODE
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>


class Solution {
  private:
    NodeCopy* dfs(Node* root, unordered_map<Node*, NodeCopy*>& m) {
      if (!root)
        return nullptr;

      NodeCopy* clone = m[root] = new NodeCopy(root->val);

      clone->left = dfs(root->left, m);
      clone->right = dfs(root->right, m);

      return clone;
    }

    void dfs(Node* root, NodeCopy* clone, unordered_map<Node*, NodeCopy*>& m) {
      if (!root)
        return;

      if (root->random)
        clone->random = m[root->random];

      dfs(root->left, clone->left, m);
      dfs(root->right, clone->right, m);
    }

  public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
      unordered_map<Node*, NodeCopy*> m;

      NodeCopy* clone = dfs(root, m);

      dfs(root, clone, m);

      return clone;
    }
};


int main() {
  EXECS(Solution::copyRandomBinaryTree);
  return 0;
}