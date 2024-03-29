#include <local_leetcode.hpp>

class Solution {
  public:
    int maxDepth(TreeNode* root) {
      return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};


int main() {
  EXECS(Solution::maxDepth);
  return 0;
}
