#include <local_leetcode.hpp>

class Solution {
  public:
    int widthOfBinaryTree(TreeNode* root) {
      queue<pair<TreeNode*, int>> q;
      if (root) q.emplace(root, 0);

      int res=0;
      while (!q.empty()) {
        res = max(res, q.back().second - q.front().second);
        int N = q.size(), base = q.front().second;
        while (N--) {
          auto [root, index] = q.front();
          q.pop();
          if (root->left) 
            q.emplace(root->left, (index - base) * 2);
          if (root->right) 
            q.emplace(root->right, (index - base) * 2 + 1);
        }
      }
      return res+1;
    }
};

int main() {
  EXECS(Solution::widthOfBinaryTree);
  return 0;
}
