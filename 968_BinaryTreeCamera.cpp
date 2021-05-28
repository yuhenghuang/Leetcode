#include <unordered_set>
#include "utils2.hpp"

class Solution {
  private:
    int res;

    void dfs(TreeNode* node, TreeNode* par, unordered_set<TreeNode*>& covered) {
      if (node) {
        dfs(node->left, node, covered);
        dfs(node->right, node, covered);

        if ((!par && covered.count(node) == 0) || 
            covered.count(node->left) == 0 || 
            covered.count(node->right) == 0) {
          // ..
          ++res;
          covered.insert(par);
          covered.insert(node);
          covered.insert(node->left);
          covered.insert(node->right);
        }
      }      
    }

  public:
    int minCameraCover(TreeNode* root) {
      res = 0;
      unordered_set<TreeNode*> covered;
      covered.insert(nullptr);

      dfs(root, nullptr, covered);
      return res;
    }
};


int main() {
  UFUNC(Solution::minCameraCover);
  return 0;
}