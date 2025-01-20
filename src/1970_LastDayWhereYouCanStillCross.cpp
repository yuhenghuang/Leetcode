#include "utils3.hpp"

class Solution {
  private:
    bool bfs(int m, int n, int t, vector<vector<int>> blockday) {
      const vector<vector<int>> dirs {{1,0}, {0,1}, {-1,0}, {0,-1}};

      queue<pair<int, int>> q;
      for (int j = 0; j < n; ++j)
        q.emplace(-1, j);

      while (!q.empty()) {
        auto [r_curr, c_curr] = q.front();
        q.pop();

        for (auto& d : dirs) {
          int r = r_curr + d[0];
          int c = c_curr + d[1];
          if (r >= 0 && r < m && c >= 0 && c < n && blockday[r][c] > t) {
            if (r == m - 1)
              return true;

            blockday[r][c] = 0;
            q.emplace(r, c);
          }
        }
      }

      return false;
    }

  public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
      int n = cells.size();

      vector<vector<int>> blockday(row, vector<int>(col));
      for (int i = 0; i < n; ++i)
        blockday[cells[i][0] - 1][cells[i][1] - 1] = i + 1;

      int l = 1, r = n;
      while (l < r) {
        int m = l + (r - l) / 2;

        if (bfs(row, col, m, blockday))
          l = m + 1;
        else
          r = m;
      }

      return l - 1;
    }
};


int main() {
  UFUNCS(Solution::latestDayToCross);
  return 0;
}