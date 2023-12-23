#include <local_leetcode.hpp>

class Solution {
  public:
    int knightDialer(int n) {
      constexpr int mod = 1e9 + 7;

      // law of motion
      const vector<int> lom[10] {
        {4, 6},
        {6, 8}, {7, 9}, {4, 8},
        {0, 3, 9}, {}, {0, 1, 7},
        {2, 6}, {1, 3}, {2, 4}
      };

      int prev[10], curr[10];

      for (int i = 0; i < 10; ++i)
        curr[i] = 1;

      for (int i = 1; i < n; ++i) {
        swap(prev, curr);
        memset(curr, 0, sizeof(curr));

        for (int j = 0; j < 10; ++j)
          for (int k : lom[j])
            if ((curr[k] += prev[j]) >= mod)
              curr[k] -= mod;
      }

      int res = 0;
      
      for (int i = 0; i < 10; ++i)
        if ((res += curr[i]) >= mod)
          res -= mod;

      return res;
    }
};


int main() {
  EXECS(Solution::knightDialer);
  return 0;
}