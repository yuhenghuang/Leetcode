#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      stack<TreeNode*, vector<TreeNode*>> s, s_next;
      if (root)
        s.push(root);

      bool flag = true;
      while (!s.empty()) {
        vector<int>& level = res.emplace_back();
        while (!s.empty()) {
          root = s.top();
          s.pop();
          level.push_back(root->val);
          if (flag && root->left)
            s_next.push(root->left);
          if (root->right)
            s_next.push(root->right);
          if (!flag && root->left)
            s_next.push(root->left); 
        }
        flag = !flag;
        swap(s, s_next);
      }
      return res;
    }
};


int main() {
  EXECS(Solution::zigzagLevelOrder);
  return 0;
}