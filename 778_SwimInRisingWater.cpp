#include "utils2.hpp"

class Solution {
  public:
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();

      vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

      vector<vector<bool>> seen(n, vector<bool>(n, false));
      seen[0][0] = true;

      // better to use priority_queue 
      // if grid[i][j] is not consecutive (from 0 to n*n - 1)
      queue<pair<int, int>> q, q_prime;
      q.emplace(0, 0);

      // this approach will fail if t is not consecutive in grid
      for (int t = grid[0][0]; t < n * n; ++t) {
        while (!q.empty()) {
          auto p = q.front();
          q.pop();

          if (grid[p.first][p.second] > t) {
            q_prime.emplace(p);
            continue;
          }

          for (vector<int>& dir : dirs) {
            int i = p.first + dir[0];
            int j = p.second + dir[1];
            if (i == n-1 && j == n-1)
              return max(grid[i][j], t);

            if (i < 0 || i == n || j < 0 || j == n || seen[i][j])
              continue;

            seen[i][j] = true;
            q.emplace(i, j);
          }
        }

        swap(q, q_prime);
      }


      return -1;
    }
};


int main() {
  UFUNC(Solution::swimInWater);
  return 0;
}