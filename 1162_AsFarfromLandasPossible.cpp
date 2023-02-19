#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  public:
    int maxDistance(vector<vector<int>>& grid) {
      int m = grid.size(), n = m==0 ? 0 : grid[0].size();
      vector<vector<bool>> seen(m, vector<bool>(n, false));
      queue<pair<int, int>> q;

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (grid[i][j]) {
            q.push(make_pair(i, j));
            seen[i][j] = true;
          }

      int res=-1;
      while (!q.empty()) {
        ++res;
        int N = q.size()+1;
        while (--N) {
          int cur_i = q.front().first, cur_j = q.front().second;
          q.pop();
          for (int k=0; k<4; ++k) {
            int i = cur_i + dir[k][0], j = cur_j + dir[k][1];
            if (i<0 || i>=m || j<0 || j>=n || seen[i][j]) continue;
            seen[i][j] = true;
            q.push(make_pair(i, j));
          }
        }
      }
      return res;
    }
};


int main() {
  EXECS(Solution::maxDistance);
  return 0;
}