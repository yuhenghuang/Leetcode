#include "DataStructure.h"
#include <cmath>
using namespace std;

class Solution {
  public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
      TreeNode* red = dfs(root, x);
      int l = dfs2(red->left), r = dfs2(red->right), u = n-l-r-1;
      return max(max(l, r), u)>n/2;
    }

    TreeNode* dfs(TreeNode* node, int& x) {
      if (!node || node->val == x) return node;
      TreeNode* l = dfs(node->left, x);
      return l ? l : dfs(node->right, x);
    }

    int dfs2(TreeNode* node) {
      if (!node) return 0;
      return 1 + dfs2(node->left) + dfs2(node->right);
    }
};