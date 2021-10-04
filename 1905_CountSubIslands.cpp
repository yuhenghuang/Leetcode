#include "utils3.hpp"

class Solution {
  private:
    bool dfs(const int m, const int n, int i, int j, const vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] < 1)
        return true;

      static const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

      grid2[i][j] = -1;

      bool res = grid1[i][j] == 1;
      for (auto& d : dirs) 
        res &= dfs(m, n, i + d[0], j + d[1], grid1, grid2);

      return res;
    }

  public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
      int m = grid1.size();
      int n = grid1[0].size();

      int res = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid2[i][j] > 0 && dfs(m, n, i, j, grid1, grid2))
            ++res;

      return res;
    }
};


int main() {
  UFUNCS(Solution::countSubIslands);
  return 0;
}