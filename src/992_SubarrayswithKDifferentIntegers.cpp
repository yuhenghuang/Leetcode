#include <local_leetcode.hpp>

class Solution {
  public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      // incomplete

      int n = nums.size();

      if (k == 1)
        return n;

      vector<int> freqs(n + 1);

      // i, j at k = 1
      unordered_map<int, int> m;
      m[-1] = 0;

      int res = 0;
      for (int i = 0; i < n; ++i) {

        int j = m[i-1];
        for (; j < n && k > -1; ++j) {
          if (k == 1)
            m[i] = j;

          if (++freqs[nums[j]] == 1)
            --k;

          if (k == 0)
            ++res;
        }

        if (--freqs[nums[i]] == 0)
            ++k;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::subarraysWithKDistinct);
  return 0;
}