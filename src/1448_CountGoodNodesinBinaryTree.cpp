#include <local_leetcode.hpp>

class Solution {
  private:
    int goodNodes(TreeNode* root, int val) {
      if (!root)
        return 0;
      else if (root->val < val)
        return goodNodes(root->left, val) + goodNodes(root->right, val);
      else
        return 1 + goodNodes(root->left, root->val) + goodNodes(root->right, root->val);
    }

  public:
    int goodNodes(TreeNode* root) {
      return goodNodes(root, INT_MIN);
    }

    int goodNodesBFS(TreeNode* root) {
      TreeNode dummy(INT_MIN, root, nullptr);

      // node, max value
      queue<pair<TreeNode*, int>> q;
      q.emplace(&dummy, INT_MIN);

      int res = 0;
      while (!q.empty()) {
        auto& [node, val] = q.front();

        if (node->left) {
          if (node->left->val >= val) {
            q.emplace(node->left, node->left->val);
            ++res;
          }
          else
            q.emplace(node->left, val);
        }

        if (node->right) {
          if (node->right->val >= val) {
            q.emplace(node->right, node->right->val);
            ++res;
          }
          else
            q.emplace(node->right, val);
        }

        q.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::goodNodes, int, (TreeNode*));
  EXECS(Solution::goodNodesBFS);
  return 0;
}
