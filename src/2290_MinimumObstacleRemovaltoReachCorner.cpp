#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    int minimumObstacles(vector<vector<int>>& grid) {
      typedef tuple<int, int, int> iii_t;

      int m = grid.size();
      int n = grid[0].size();

      vector<vector<bool>> seen(m, vector<bool>(n));

      // obstacles, i, j
      priority_queue<iii_t, vector<iii_t>, greater<iii_t>> heap;

      heap.emplace(0, 0, 0);

      while (!heap.empty()) {
        auto [d, i, j] = heap.top();
        heap.pop();

        if (!seen[i][j]) {
          seen[i][j] = true;
          
          for (auto& dir : dirs) {
            int r = i + dir[0];
            int c = j + dir[1];

            if (r == m-1 && c == n-1)
              return d;

            if (r >= 0 && r < m && c >= 0 && c < n && !seen[r][c])
              heap.emplace(d + grid[r][c], r, c);
          }
        }
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::minimumObstacles);
  return 0;
}