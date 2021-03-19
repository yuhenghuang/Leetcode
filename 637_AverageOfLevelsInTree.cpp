#include "utils2.hpp"


class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> q;
      
      if (root)
        q.push(root);
      
      vector<double> res;
      while (!q.empty()) {
        int n = q.size();
        double sum = 0.0;
        for (int i=0; i<n; ++i) {
          root = q.front(); q.pop();
          sum += root->val;
          
          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
        
        res.push_back(sum / n);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::averageOfLevels);
  return 0;
}