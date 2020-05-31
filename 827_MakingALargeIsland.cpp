#include <vector>
#include <set>
using namespace std;

class Solution {
  private:
    int m, n;
    vector<int> parent, islands;
    vector<vector<bool>> seen;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  public:
    int largestIsland(vector<vector<int>>& grid) {
      m = grid.size();
      n = m==0 ? 0 : grid[0].size();
      parent = vector<int>(m*n);
      islands = vector<int>(m*n+1, 0); // size of island, indexed by parent. last position for outside of grid;
      seen = vector<vector<bool>>(m, vector<bool>(n, false));

      for (int i=0; i<m*n; ++i)
        parent[i] = i;

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          dfs(i, j, i*n+j, grid);

      int res=0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          res = max(res, (grid[i][j]) ? islands[parent[i*n+j]] : around(i, j));
      return res;
    }

    void dfs(int i, int j, int p, vector<vector<int>>& grid) {
      if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || seen[i][j])
        return;

      seen[i][j] = true;
      parent[i*n+j] = p;
      ++islands[p];
      for (int k=0; k<4; ++k)
        dfs(i+dir[k][0], j+dir[k][1], p, grid);
    }

    int around(int i, int j) {
      set<int> sur;
      for (int k=0; k<4; ++k)
        sur.insert(helper(i+dir[k][0], j+dir[k][1]));

      int res=1;
      for (const int& idx : sur)
        res += islands[idx];
      return res;
    }

    int helper(int i, int j) {
      // return parent id if legal
      if (i<0 || i>=m || j<0 || j>=n)
        return m*n; // last index of islands[]
      else 
        return parent[i*n + j];
    }
};