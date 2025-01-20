#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int dirs[8][2] {{1,2},{2,1}, {-1,2},{-2,1}, {1,-2},{2,-1}, {-1,-2},{-2,-1}};

  public:
    double knightProbability(const int n, int k, int row, int column) {
      double prev[625], next[625];

      memset(prev, 0, sizeof(double) * n * n);
      prev[row*n + column] = 1.0;

      while (k--) {
        memset(next, 0, sizeof(double) * n * n);

        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (prev[i*n + j] > 0)
              for (auto& d : dirs) {
                int r = i + d[0];
                int c = j + d[1];
                if (0 <= r && r < n && 0 <= c && c < n)
                  next[r*n + c] += prev[i*n + j] / 8;
              }

        swap(prev, next);
      }

      return reduce(begin(prev), begin(prev) + n*n);
    }
};


int main() {
  EXECS(Solution::knightProbability);
  return 0;
}