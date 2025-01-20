#define _LL_FLATTEN_2D
#include <local_leetcode.hpp>

class Solution {
  private:
    void traverse(TreeNode* root, int i, int j, map<int, multiset<pair<int, int>>>& m) {
      if (!root)
        return;

      m[i].emplace(j, root->val);

      traverse(root->left, i-1, j+1, m);
      traverse(root->right, i+1, j+1, m);
    }
  public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      map<int, multiset<pair<int, int>>> m;

      traverse(root, 0, 0, m);
      
      vector<vector<int>> res;
      res.reserve(m.size());

      for (auto outer_iter = m.begin(); outer_iter!=m.end(); ++outer_iter) {
        vector<int>& vec = res.emplace_back();
        vec.reserve(outer_iter->second.size());

        auto inner_end = outer_iter->second.end();
        for (auto inner_iter = outer_iter->second.begin(); inner_iter!=inner_end; ++inner_iter)
          vec.push_back(inner_iter->second);
      }

      return res;
    }

    vector<vector<int>> verticalTraversalIter(TreeNode* root) {
      map<int, multiset<pair<int, int>>> m;

      traverse(root, 0, 0, m);
      
      vector<vector<int>> res;
      res.reserve(m.size());

      for (auto& [r, c] : m) {
        vector<int>& vec = res.emplace_back();
        vec.reserve(c.size());

        transform(c.begin(), c.end(), back_insert_iterator(vec), mem_fn(&pair<int, int>::second));
      }

      return res;
    }

    vector<vector<int>> verticalTraversalBFS(TreeNode* root) {
      typedef pair<int, int> ii_t;
      typedef tuple<int, int, int> iii_t;

      // row, column, value
      vector<vector<ii_t>> coords;

      // node, column
      queue<pair<TreeNode*, int>> q;

      if (root)
        q.emplace(root, 0);

      while (!q.empty()) {
        int n = q.size();
        
        vector<ii_t>& row = coords.emplace_back();
        row.reserve(n);

        while (n--) {
          auto& [node, col] = q.front();
          row.emplace_back(col, node->val);

          if (node->left) q.emplace(node->left, col - 1);
          if (node->right) q.emplace(node->right, col + 1);

          q.pop();
        }
      }

      // column, row, value
      vector<iii_t> nodes;

      for (int r = 0; r < coords.size(); ++r)
        for (auto& [c, v] : coords[r])
          nodes.emplace_back(c, r, v);

      sort(nodes.begin(), nodes.end());

      int curr_col = INT_MIN;
      vector<vector<int>> res;

      for (auto& [c, r, v] : nodes) {
        if (c > curr_col) {
          curr_col = c;
          res.emplace_back();
        }

        res.back().push_back(v);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::verticalTraversal);
  EXECS(Solution::verticalTraversalIter);
  EXECS(Solution::verticalTraversalBFS);
  return 0;
}
