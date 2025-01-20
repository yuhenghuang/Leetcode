#include <local_leetcode.hpp>

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

    int countNodesOlog2n(TreeNode* root) {
      // time complexity: O(logn * logn)

      int height = 0; // the height of rightmost right node
      for (TreeNode* node = root; node != nullptr; ++height, node = node->right);

      // index of node on last layer (from left to right, 0-base)
      int l = 0, r = (1 << height) - 1;

      // O(logn), binary search
      while (l <= r) {
        int m = l + (r - l) / 2;

        // find node on last layer given index m O(logn)
        TreeNode* node = root;
        for (int h = height - 1, i = m; h >= 0; --h) {
          if (i < (1 << h))
            node = node->left;
          else {
            node = node->right;
            i -= 1 << h;
          }
        }

        if (node == nullptr)
          r = m - 1;
        else
          l = m + 1;
      }

      // (nodes of 1 ~ height layers) + (nodes of height + 1 layer)
      // 2 ^ height - 1             + (size of height + 1 layer)
      // 2 ^ height - 1             + m + 1
      // 2 ^ height + m
      return (1 << height) + r;
    }
};

int main() {
  EXECS(Solution::countNodes);
  EXECS(Solution::countNodesOlogn);
  EXECS(Solution::countNodesOlog2n);
  return 0;
}
