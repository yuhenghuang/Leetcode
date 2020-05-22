#include "DataStructure.h"
#include <iostream>
using namespace std;

class Solution {
  public:
    void flatten(TreeNode* root) {
      dfs(root);
    }
    TreeNode* dfs(TreeNode* node) {
      if (!node) return nullptr;
      TreeNode* l = dfs(node->left);
      TreeNode* r = dfs(node->right);

      if (!l && !r) 
        return node;
      else if (!l) 
        return r;
      else if (!r) {
        node->right = node->left;
        node->left = nullptr;
        return l;
      }
      else {
        l->right = node->right;
        node->right = node->left;
        node->left = nullptr;
        return r;
      }
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);

  Solution sol;
  sol.flatten(root);

  TreeNode* node = root;
  while (node) {
    cout << node->val << endl;
    node = node->right;
  }
  return 0;
}