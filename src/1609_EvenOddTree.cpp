#include <local_leetcode.hpp>

class Solution {
  private:
    bool dfs(TreeNode* root, vector<int>& vals, int level) {
      if (!root)
        return true;

      if (vals.size() == level)
        vals.push_back(root->val);
      else if (level & 1) {
        if (vals[level] <= root->val)
          return false;
      }
      else {
        if (vals[level] >= root->val)
          return false;
      }

      vals[level] = root->val;

      return ((root->val & 1) ^ (level & 1)) && dfs(root->left, vals, level + 1) && dfs(root->right, vals, level + 1);
    }

  public:
    bool isEvenOddTree(TreeNode* root) {
      vector<int> vals;
      return dfs(root, vals, 0);
    }

    bool isEvenOddTreeBFS(TreeNode* root) {
      queue<TreeNode*> q;

      if (root)
        q.push(root);

      int level = 0;
      while (!q.empty()) {
        int n = q.size();

        int val;
        function<bool (const int&, const int&)> comp;

        if (level & 1) {
          val = INT_MAX;
          comp = less_equal<int>();
        }
        else {
          val = INT_MIN;
          comp = greater_equal<int>();
        }

        while (n--) {
          root = q.front();
          q.pop();
        
          if (((root->val & 1) ^ level) == 0 || comp(val, root->val))
            return false;

          val = root->val;

          if (root->left)
            q.push(root->left);
          if (root->right)
            q.push(root->right);
        }

        level ^= 1;
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isEvenOddTree);
  EXECS(Solution::isEvenOddTreeBFS);
  return 0;
}