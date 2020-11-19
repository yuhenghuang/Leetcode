#define PERFECT_BINARY_TREE_NODE
#include "DataStructure.h"

class Solution {
  private:
    void dfs(Node* root) {
      if (!root) return;
      
      Node* p = nullptr;
      if (root->left && root->right) {
        root->left->next = root->right;
        p = root->right;
      }
      else if (root->left)
        p = root->left;
      else if (root->right)
        p = root->right;

      if (p) {
        Node* q = root->next;
        while (q && !q->left && !q->right)
          q = q->next;

        p->next = q ? (q->left ? q->left : q->right) : nullptr;
      }

      dfs(root->right);
      dfs(root->left);
    }
  public:
    Node* connect(Node* root) {
      dfs(root);
      return root;
    }
};