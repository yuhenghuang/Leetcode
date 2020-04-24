#include "DataStructure.cpp"
using namespace std;

class Solution {
  public:
    int sumRootToLeaf(TreeNode* root) {
      return dfs(root, 0);
    }
    int dfs(TreeNode*root, int acc) {
      if (root==nullptr) return 0;
      acc = (acc << 1) + root->val;
      if (root->left==nullptr && root->right==nullptr) return acc;
      return dfs(root->left, acc) + dfs(root->right, acc);
    }
};