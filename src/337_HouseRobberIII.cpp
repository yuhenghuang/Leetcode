#include "utils.hpp"

using namespace std;

class Solution {
  private:
    int dfs(TreeNode* root, bool skip = false, bool value = false) {
      if (!root) 
        return 0;
      else if (value) {
        return root->val;
      }
      else if (skip) {
        return dfs(root->left, false, true) + dfs(root->right, false, true);
      }
      else {
        root->val = max(dfs(root->left) + dfs(root->right), root->val + dfs(root->left, true) + dfs(root->right, true));
        return root->val;
      }
    }
  public:
    int rob(TreeNode* root) {
      return dfs(root);
    }
};

int main() {
  UFUNC(Solution::rob);
  return 0;
}
