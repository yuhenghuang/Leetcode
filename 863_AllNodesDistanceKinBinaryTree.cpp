#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs1(TreeNode* root, TreeNode* target, vector<TreeNode*>& s, vector<TreeNode*>& path) {
      if (!path.empty() || !root)
        return;

      s.push_back(root);

      if (root == target)
        path = s;

      dfs1(root->left, target, s, path);
      dfs1(root->right, target, s, path);

      s.pop_back();
    }

    void dfs2(TreeNode* root, int dist, vector<int>& res) {
      if (!root)
        return;
      else if (dist == 0) {
        res.push_back(root->val);
        return;
      }

      dfs2(root->left, dist - 1, res);
      dfs2(root->right, dist - 1, res);
    }

  public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      if (k == 0)
        return {target->val};

      vector<TreeNode*> s;

      // path from root to target
      vector<TreeNode*> path;

      dfs1(root, target, s, path);

      vector<int> res;

      int n = path.size() - 1;

      if (n - k >= 0)
        res.push_back(path[n - k]->val);

      for (int i = max(0, n - k + 1); i < n; ++i) 
        dfs2(path[i]->left == path[i+1] ? path[i]->right : path[i]->left, k - 1 - n + i, res);

      dfs2(target, k, res);

      return res;
    }

    vector<int> distanceK(TreeNode* root, int target, int k) {
      return distanceK(
        root,
        ll::find_node(root, target),
        k
      );
    }
};


int main() {
  EXECS(Solution::distanceK, vector<int>, (TreeNode*, int, int));
  return 0;
}