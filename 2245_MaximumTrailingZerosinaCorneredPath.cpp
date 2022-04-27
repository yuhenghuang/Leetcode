#include <local_leetcode.hpp>

class Solution {
  private:
    struct count25 {
      int count2;
      int count5;
      
      count25(): count2(0), count5(0) { }

      count25(int _count2, int _count5): count2(_count2), count5(_count5) { }

      count25(int num): count2(0), count5(0) {
        while (num > 0 && (num & 1) == 0) {
          ++count2;
          num >>= 1;
        }

        while (num > 0 && num % 5 == 0) {
          ++count5;
          num /= 5;
        }
      }

      count25 operator+(const count25& rhs) const {
        return {count2 + rhs.count2, count5 + rhs.count5};
      }

      count25 operator-(const count25& rhs) const {
        return {count2 - rhs.count2, count5 - rhs.count5};
      }

      int trailingZeros(const count25& v, const count25& h) {
        return min(count2 + v.count2 + h.count2, count5 + v.count5 + h.count5);
      }
    };

  public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      // row prefix sum
      vector<vector<count25>> rows(m, vector<count25>(n + 1));

      // col prefix sum
      vector<vector<count25>> cols(n, vector<count25>(m + 1));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          rows[i][j+1] = rows[i][j] + count25(grid[i][j]);

      for (int j = 0; j < n; ++j)
        for (int i = 1; i < m; ++i)
          cols[j][i+1] = cols[j][i] + count25(grid[i][j]);

      int res = 0;

      count25 horizontal[2];
      count25 vertical[2];
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          count25 center(grid[i][j]);

          vertical[0] = cols[j][i];
          vertical[1] = cols[j][m] - cols[j][i+1];

          horizontal[0] = rows[i][j];
          horizontal[1] = rows[i][n] - rows[i][j+1];

          for (auto& v : vertical)
            for (auto& h : horizontal)
              res = max(res, center.trailingZeros(v, h));
        }

      return res;
    }
};


int main() {
  EXECS(Solution::maxTrailingZeros);
  return 0;
}