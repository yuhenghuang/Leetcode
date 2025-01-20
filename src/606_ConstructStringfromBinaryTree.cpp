#include <local_leetcode.hpp>

class Solution {
  public:
    string tree2str(TreeNode* root) {
      if (!root->left && !root->right)
        return to_string(root->val);
      else if (!root->left) 
        return to_string(root->val) + "()(" + tree2str(root->right) + ')';
      else if (!root->right)
        return to_string(root->val) + '(' + tree2str(root->left) + ')';
      else
        return to_string(root->val) + '(' + tree2str(root->left) + ')' + '(' + tree2str(root->right) + ')';
    }
};


int main() {
  EXECS(Solution::tree2str);
  return 0;
}
