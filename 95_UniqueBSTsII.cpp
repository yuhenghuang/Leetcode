#define _DELETE_RETURN_POINTER
#include "utils3.hpp"

class Solution {
  private:
    vector<TreeNode*> dfs(int i, int j) {
      if (i > j)
        return {nullptr};

      vector<TreeNode*> res;
      for (int k = i; k <= j; ++k) {
        for (auto l : dfs(i, k - 1))
          for (auto r : dfs(k + 1, j))
            res.push_back(new TreeNode(k, l, r));
      }

      return res;
    }

  public:
    vector<TreeNode*> generateTrees(int n) {
      return dfs(1, n);
    }
};


int main() {
  UFUNCS(Solution::generateTrees);
  return 0;
}