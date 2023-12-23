#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool canEscape(vector<vector<bool>> seen, vector<vector<ii_t>>& fires, int k) const {
      const int m = seen.size();
      const int n = seen[0].size();
      
      // apply first k days' fire
      for (int i = 0; i < k; ++i)
        for (auto& [r, c] : fires[i])
          seen[r][c] = true;

      queue<ii_t> q;
      q.emplace(0, 0);

      // why you move first and then fire spreads
      // -> solve corner case where you and fire reach the safe house simultaneously
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto& [r, c] = q.front();

          // no fire and not visited
          if (!seen[r][c]) {
            seen[r][c] = true;

            for (auto& d : dirs) {
              int i = r + d[0];
              int j = c + d[1];
              if (i >= 0 && i < m && j >= 0 && j < n && !seen[i][j]) {
                if (i == m - 1 && j == n - 1)
                  return true;

                q.emplace(i, j);
              }
            }
          }

          q.pop();
        }

        // fire spreads at day k + 1
        if (k < fires.size()) {
          for (auto& [r, c] : fires[k])
            seen[r][c] = true;

          ++k;
        }
      }

      return false;
    }

  public:
    int maximumMinutes(vector<vector<int>>& grid) {
      // time: O(log(mn)mn)
      // memory: O(mn)

      const int m = grid.size();
      const int n = grid[0].size();

      // new fires at [r, c] on day i
      vector<vector<ii_t>> fires;

      // scope to compute the spreading of fires day by day
      {
        vector<vector<bool>> seen(m, vector<bool>(n));
        queue<ii_t> q;

        for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
            if (grid[i][j] != 0) {
              seen[i][j] = true;

              if (grid[i][j] == 1)
                q.emplace(i, j);
            }

        while (!q.empty()) {
          vector<ii_t>& f = fires.emplace_back();

          int N = q.size();
          while (N--) {
            auto& [r, c] = q.front();

            for (auto& d : dirs) {
              int i = r + d[0];
              int j = c + d[1];
              if (i >= 0 && i < m && j >= 0 && j < n && !seen[i][j]) {
                seen[i][j] = true;
                q.emplace(i, j);
                f.emplace_back(i, j);
              }
            }

            q.pop();
          }
        }

        // remove last empty day
        if (!fires.empty() && fires.back().empty())
          fires.pop_back();
      }

      // initial condition of the grid
      // false -> wall, visited or fire
      vector<vector<bool>> seen(m, vector<bool>(n));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] != 0)
            seen[i][j] = true;


      int l = 0, r = (int) fires.size();
      while (l <= r) {
        int k = l + (r - l) / 2;

        if (canEscape(seen, fires, k))
          l = k + 1;
        else
          r = k - 1;
      }

      return r == fires.size() ? 1e9 : r;
    }
};


int main() {
  EXECS(Solution::maximumMinutes);
  return 0;
}