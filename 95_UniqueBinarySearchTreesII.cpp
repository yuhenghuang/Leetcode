// #define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

#define N 8

class Solution {
  private:
    static vector<TreeNode> nodes;
    static vector<TreeNode*> trees[N+2][N+2];

    static bool helper;
    static bool init() {
      // prevent the copy of nodes, which causes the address of nodes to change
      nodes.reserve(3000);

      for (int i = 0; i <= N; ++i)
        trees[i+1][i].push_back(nullptr);

      for (int i = N; i > 0; --i) // left bound
        for (int j = i; j <= N; ++j) // right bound
          for (int k = i; k <= j; ++k) // root of the subtree over [i, j]
            for (auto l : trees[i][k-1]) // left node(s) of the subtree
              for (auto r : trees[k+1][j]) // right node(s) of the subtree
                trees[i][j].push_back(&nodes.emplace_back(k, l, r));

      return true;
    }

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

    vector<TreeNode*> generateTreesStatic(int n) {
      return trees[1][n];
    }
};

vector<TreeNode> Solution::nodes;
vector<TreeNode*> Solution::trees[N+2][N+2];


bool Solution::helper = init();


int main() {
  // EXECS(Solution::generateTrees);
  EXECS(Solution::generateTreesStatic);
  return 0;
}