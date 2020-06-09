#include "DataStructure.h"
#include <climits>
// using namespace std;

class Solution {
  private:
    int res;
  public:
    int goodNodes(TreeNode* root) {
      res = 0;
      dfs(root, INT_MIN);
      return res;
    }
    void dfs(TreeNode* node, int val) {
      if (!node) return;
      if (node->val>=val) {
        ++res;
        val = node->val;
      }

      dfs(node->left, val);
      dfs(node->right, val);
    }
};