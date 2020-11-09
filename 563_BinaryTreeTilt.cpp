#include "utils.hpp"
#include <stack>
#include <unordered_map>

class Solution {
  private:
    int res;
    int dfs(TreeNode* root) {
      if (!root) return 0;

      int l = dfs(root->left);
      int r = dfs(root->right);
      res += abs(l - r);

      return l + r + root->val;
    }
  public:
    int findTilt(TreeNode* root) {
      res = 0;
      dfs(root);
      return res;
    }

    int findTiltIter(TreeNode* root) {
      stack<TreeNode*> s;
      unordered_map<TreeNode*, int> m;
      TreeNode* super;

      int res = 0;
      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        while (!s.empty() && !s.top()->right) {
          root = s.top();
          s.pop();

          if (!s.empty()) {
            super = s.top();
            super->val += root->val;

            if (super->right)
              m[super] = root->val;
            else
              res += abs(m[super] - root->val);
          }
        }

        if (!s.empty()) {
          root = s.top()->right;
          s.top()->right = nullptr;
        }
        else
          root = nullptr;
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::findTilt);
  }
  {
    UFUNC(Solution::findTiltIter);
  }
  return 0;
}