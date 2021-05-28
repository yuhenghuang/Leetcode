#include "utils2.hpp"

class Solution {
  private:
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
  public:
    void flattenRecursive(TreeNode* root) {
      dfs(root);
    }

    void flatten(TreeNode* root) {
      // iteration

      stack<TreeNode*> s;
      s.push(nullptr);

      while (root) {

        if (root->left) {
          if (root->right)
            s.push(root->right);

          root->right = root->left;
          root->left = nullptr;
        }
        else if (!root->right) {
          root->right = s.top();
          s.pop();
        }

        root = root->right;
      }
    }
};

int main() {
  {
    UFUNC(Solution::flattenRecursive);
  }
  {
    UFUNC(Solution::flatten);
  }

  return 0;
}