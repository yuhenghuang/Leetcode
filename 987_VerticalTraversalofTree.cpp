#include "utils2.hpp"
#include <set>

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
          vec.emplace_back(inner_iter->second);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::verticalTraversal);
  return 0;
}