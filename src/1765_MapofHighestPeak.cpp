#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    static constexpr int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

  public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
      const int m = isWater.size();
      const int n = isWater[0].size();

      queue<ii_t> q;

      vector<vector<int>> res(m, vector<int>(n, INT_MAX));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (isWater[i][j]) {
            q.emplace(i, j);
            res[i][j] = 0;
          }

      while (not q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        int h = res[i][j];
        for (auto& d : dirs) {
          int r = i + d[0];
          int c = j + d[1];
          if (0 <= r and r < m and 0 <= c and c < n and res[r][c] == INT_MAX) {
            res[r][c] = h + 1;
            q.emplace(r, c);
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::highestPeak);
  return 0;
}