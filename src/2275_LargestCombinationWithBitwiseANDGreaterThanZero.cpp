#include <local_leetcode.hpp>

class Solution {
  public:
    int largestCombination(vector<int>& candidates) {
      // subsequence version
      int n = candidates.size();

      int count[24];
      memset(count, 0, sizeof(count));

      for (int i = 0; i < n; ++i)
        for (int j = 0; j < 24; ++j)
          if (candidates[i] & (1 << j))
            ++count[j];

      return *max_element(begin(count), end(count));
    }

    int largestCombinationWrong(vector<int>& candidates) {
      // subarray version

      int n = candidates.size();

      int res = 1;

      int index[24];
      memset(index, -1, sizeof(index));

      for (int i = 0; i < n; ++i) {
        int num = candidates[i];
        for (int j = 0; j < 24; ++j) {
          if ((num & 1)) {
            if (index[j] == -1)
              index[j] = i;
            else if (i - index[j] + 1 > res)
              res = i - index[j] + 1;
          } else
            index[j] = -1;

          num >>= 1;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::largestCombination);
  return 0;
}