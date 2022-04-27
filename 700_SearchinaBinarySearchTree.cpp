#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* searchBST(TreeNode* root, int val) {
      if (root==nullptr) return nullptr;
      else if (root->val==val) return root;
      else if (root->val>val) return searchBST(root->left, val);
      else return searchBST(root->right, val);
    }
};


int main() {
  EXECS(Solution::searchBST);
  return 0;
}
