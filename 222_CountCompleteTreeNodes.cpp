#include "utils3.hpp"

class Solution {
  private:
    int height, idx;
  public:
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      height=0; idx=0;
      dfs(root, 0, 0);
      return (1 << (height-1)) + idx/2;
    }

    void dfs(TreeNode* node, int h, int i) {
      if (!node) {
        if (h>height) {
          height = h;
          idx = i;
        }
        else if (h==height && i>idx) {
          idx = i;
        }
        return;
      }

      dfs(node->right, h+1, i*2+1);
      dfs(node->left, h+1, i*2);
    }

    int countNodesOlogn(TreeNode* root) {
      // not necessarily O(logn), sad
      if (!root) return 0;

      int h = 0;
      TreeNode* node = root;

      while (node) {
        node = node->left;
        ++h;
      }
      
      root->val = 0;
      stack<TreeNode*> s;

      while (true) {
        while (root) {
          if (root->left)
            root->left->val = root->val * 2;
          if (root->right)
            root->right->val = root->val * 2 + 1;

          s.push(root);
          root = root->right;
        }

        if (s.size() == h)
          break;
        else if (s.top()->left) {
          s.push(s.top()->left);
          break;
        }

        s.pop();
        root = s.top()->left;
      }

      return (1 << (h - 1)) + s.top()->val;
    }
};

int main() {
  UFUNCS(Solution::countNodes);
  UFUNCS(Solution::countNodesOlogn);
  return 0;
}
