#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

  public:
    int shortestPath(vector<vector<int>>& grid, int k) {
      typedef tuple<int, int, int> iii_t;

      int m = grid.size();
      int n = grid[0].size();

      k = min(k, m + n - 1);

      vector<int> dp[k + 1];
      for (int i = 0; i <= k; ++i) {
        dp[i].assign(m * n, INT_MAX);
      }

      // eliminated obstacles, distance, i * n + j
      queue<iii_t> q;
      q.emplace(0, 0, 0);

      while (!q.empty()) {
        auto [e, dist, p] = q.front();
        q.pop();

        if (dp[e][p] <= dist)
          continue;

        dp[e][p] = dist;

        int i = p / n;
        int j = p % n;

        if (i == m - 1 && j == n - 1)
          return dist;

        for (auto& d : dirs) {
          int r = i + d[0];
          int c = j + d[1];

          if (r >= 0 && r < m && c >= 0 && c < n && e + grid[r][c] <= k)
            q.emplace(e + grid[r][c], dist + 1, r * n + c);
        }
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::shortestPath);
  return 0;
}