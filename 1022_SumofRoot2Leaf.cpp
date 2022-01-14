#include <local_leetcode.hpp>

class Solution {
  private:
    int dfs(TreeNode*root, int acc) {
      if (root==nullptr) 
        return 0;

      acc = (acc << 1) + root->val;

      // leaf found
      if (root->left==nullptr && root->right==nullptr) 
        return acc;

      return dfs(root->left, acc) + dfs(root->right, acc);
    }

  public:
    int sumRootToLeaf(TreeNode* root) {
      return dfs(root, 0);
    }
};


int main() {
  EXECS(Solution::sumRootToLeaf);
  return 0;
}