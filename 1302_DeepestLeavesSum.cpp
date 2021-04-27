#include "utils2.hpp"

class Solution {
public:
    int deepestLeavesSumBFS(TreeNode* root) {
      queue<TreeNode*> q;
      if (root) q.push(root);

      int res = 0;
      while (!q.empty()) {
        res = 0;
        int n = q.size();
        while (n--) {
          root = q.front(); q.pop();
          res += root->val;

          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
      }

      return res;
    }

    int deepestLeavesSum(TreeNode* root) {
      int depth = 0;
      return dfs(root, depth);
    }

    int dfs(TreeNode* root, int& depth) {
      if (!root) return 0;
      depth++;
      if (!root->left && !root->right) return root->val;

      int depth_l =0, depth_r=0;
      int sum_l = dfs(root->left, depth_l), sum_r = dfs(root->right, depth_r);
      if (depth_l>depth_r) {
        depth += depth_l;
        return sum_l;
      }
      else {
        depth += depth_r;
        if (depth_l<depth_r) 
          return sum_r;
        else
          return sum_l + sum_r;
      }
    }
};


int main() {
  {
    UFUNC(Solution::deepestLeavesSum);
  }
  {
    UFUNC(Solution::deepestLeavesSumBFS);
  }
  return 0;
}