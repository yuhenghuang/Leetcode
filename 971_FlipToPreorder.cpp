#include "utils2.hpp"

class Solution {
  public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      int n = voyage.size();
      
      int i = 0;
      vector<int> res;
      
      stack<TreeNode*> s;
      s.push(root);
      
      while (!s.empty()) {
        root = s.top(); s.pop();
        if (!root) continue;
        
        if (root->val == voyage[i++]) {
          if (root->left && root->left->val != voyage[i]) {
            res.push_back(root->val);
            s.push(root->left);
            s.push(root->right);
          }
          else {
            s.push(root->right);
            s.push(root->left);
          }
        }
        else
          return {-1};
      }
      
      
      return res;
    }
};


int main() {
  UFUNC(Solution::flipMatchVoyage);
  return 0;
}