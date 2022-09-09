#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int64_t, int> li_t;

    void dfs(TreeNode* root, size_t level, vector<li_t>& vec) {
      if (!root)
        return;
      else if (level == vec.size())
        vec.emplace_back();

      auto& [s, n] = vec[level++];

      s += root->val;
      ++n;

      dfs(root->left, level, vec);
      dfs(root->right, level, vec);
    }

  public:
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> q;
      
      if (root)
        q.push(root);
      
      vector<double> res;
      while (!q.empty()) {
        int n = q.size();
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
          root = q.front(); q.pop();
          sum += root->val;
          
          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
        
        res.push_back((double) sum / n);
      }
      
      return res;
    }

    vector<double> averageOfLevelsDFS(TreeNode* root) {
      // sum of current level, count of current level
      vector<li_t> vec;

      dfs(root, 0, vec);

      vector<double> res(vec.size());

      transform(vec.begin(), vec.end(), res.begin(), [](const li_t& p) { return p.first / (double) p.second; });

      return res;
    }
};


int main() {
  EXECS(Solution::averageOfLevels);
  EXECS(Solution::averageOfLevelsDFS);
  return 0;
}
