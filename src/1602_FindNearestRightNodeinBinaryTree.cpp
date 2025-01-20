#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
      queue<TreeNode*> q;

      if (root)
        q.push(root);

      while (!q.empty()) {
        int n = q.size();

        while (n--) {
          root = q.front();
          q.pop();

          if (root == u)
            return (q.empty() || n == 0) ? nullptr : q.front();

          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
      }

      return nullptr;
    }

    int findNearestRightNode(TreeNode* root, int u) {
      TreeNode* node = findNearestRightNode(root, ll::find_node(root, u));

      return node ? node->val : 0;
    }
};


int main() {
  EXECS(Solution::findNearestRightNode, int, (TreeNode*,  int));
  return 0;
}