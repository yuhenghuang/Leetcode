#include "DataStructure.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      stack<TreeNode*> s;
      if (root)
        s.push(root);

      bool flag = true;
      while (!s.empty()) {
        res.push_back({});
        stack<TreeNode*> s_temp;
        vector<int>& temp = res.back();
        while (!s.empty()) {
          root = s.top();
          temp.push_back(root->val);
          if (flag && root->left)
            s_temp.push(root->left);
          if (root->right)
            s_temp.push(root->right);
          if (!flag && root->left)
            s_temp.push(root->left); 
          s.pop();
        }
        flag = !flag;
        s = s_temp;
      }
      return res;
    }
};