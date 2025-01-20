#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<TreeNode*, int> pti;

    pti dfs(TreeNode* root, int sum, int limit) {
      sum += root->val;

      if (root->left && root->right) {
        pti&& lp = dfs(root->left, sum, limit);
        pti&& rp = dfs(root->right, sum, limit);

        root->left = lp.first;
        root->right = rp.first;

        sum = max(lp.second, rp.second);
      }
      else if (root->left || root->right) {
        TreeNode* TreeNode::*child = root->left ? &TreeNode::left : &TreeNode::right;
        pti&& p = dfs(root->*child, sum, limit);

        root->*child = p.first;
        sum = p.second;
      }

      return {sum < limit ? nullptr : root, sum};
    }

  public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
      if (!root)
        return nullptr;

      return dfs(root, 0, limit).first;
    }
};


int main() {
  EXECS(Solution::sufficientSubset);
  return 0;
}