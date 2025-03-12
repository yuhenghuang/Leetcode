#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumRecolors(string blocks, int k) {
      int res = 0;

      int temp = 0;
      for (int i = 0; i < (int) blocks.size(); ++i) {
        // count black blocks over (i-k, i]

        if (blocks[i] == 'B')
          ++temp;

        if (int j = i - k; j >= 0 and blocks[j] == 'B')
          --temp;

        if (temp > res)
          res = temp;
      }

      return k - res;
    }
};


int main() {
  EXECS(Solution::minimumRecolors);
  return 0;
}