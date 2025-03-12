#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      // wrong answer

      const int n = grid.size();
      const int N = n * n;

      int diff = 0; // repeated - missing
      int modor = 0; // repeated ^ missing
      for (int i = 1; i <= N; ++i) {
        int r = (i - 1) / n;
        int c = (i - 1) % n;

        diff += grid[r][c] - i;
        modor ^= grid[r][c] ^ i;
      }

      for (int i = 1; i <= N; ++i)
        if (i - (i ^ modor) == diff)
          return {i, i ^ modor};

      return {};
    }
};


int main() {
  EXECS(Solution::findMissingAndRepeatedValues);
  return 0;
}