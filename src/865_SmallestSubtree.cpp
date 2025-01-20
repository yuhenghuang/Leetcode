#include "utils.hpp"

class Solution {
  public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      if (!root) return nullptr;

      queue<pair<int, TreeNode*>> q;
      q.push({0, root});

      int depth=-1, left, right;
      while (!q.empty()) {
        int N = q.size();
        left = q.front().first;
        right = q.back().first;
        while (N--) {
          auto& p = q.front();
          int idx = p.first;
          TreeNode* node = p.second;
          q.pop();

          if (node->left)
            q.push({idx*2, node->left});
          if (node->right)
            q.push({idx*2+1, node->right});
        }
        ++depth;
      }

      while (left!=right) {
        left /= 2;
        right /= 2;
        --depth;
      }

      while (depth--) {
        if (left < (1 << depth)) 
          root = root->left;
        else {
          root = root->right;
          left -= 1 << depth;
        }
      }

      return root;
    }
};


int main() {
  UFUNC(Solution::subtreeWithAllDeepest);
  return 0;
}