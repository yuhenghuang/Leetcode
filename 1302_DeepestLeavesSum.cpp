#include "DataStructure.h"

class Solution {
public:
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