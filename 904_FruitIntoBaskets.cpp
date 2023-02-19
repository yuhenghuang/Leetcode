#include <local_leetcode.hpp>

class Solution {
  public:
    int totalFruit(vector<int>& fruits) {
      // sliding window

      int n = fruits.size();

      int count[n]; // count of fruits by type in sliding windows
      memset(count, 0, sizeof(count));

      int res = 0;
      int types = 0; // num. of fruits' types

      int i = 0; // left bound
      for (int j = 0; j < n; ++j) { // right bound

        // move right bound
        if (count[fruits[j]]++ == 0)
          ++types;

        // move left bound
        for (; types > 2; ++i)
          if (--count[fruits[i]] == 0)
            --types;

        // update max length
        if (res < j - i + 1)
          res = j - i + 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::totalFruit);
  return 0;
}