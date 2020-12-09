#include "utils.hpp"

class Solution {
  private:
    TreeNode* curr;
    void dfs(TreeNode* root) {
      if (!root) return;

      dfs(root->left);
      root->left = nullptr;
      curr->right = root;
      curr = root;
      dfs(root->right);
    }
  public:
    TreeNode* increasingBST(TreeNode* root) {
      TreeNode* dummy = new TreeNode();
      curr = dummy;
      dfs(root);
      return dummy->right;
    }

    TreeNode* increasingBSTIter(TreeNode* root) {
      TreeNode* dummy = new TreeNode();
      TreeNode* curr = dummy;
      stack<TreeNode*> s;

      while(!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();

        root->left = nullptr;
        curr->right = root;
        curr = root;
        root = root->right;
      }

      return dummy->right;
    }
};


int main() {
  {
    UFUNC(Solution::increasingBST);
  }
  {
    UFUNC(Solution::increasingBSTIter);
  }
  return 0;
}