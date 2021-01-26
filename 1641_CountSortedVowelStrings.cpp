#include "utils.hpp"

class Solution {
  public:
    int countVowelStrings(int n) {
      // vector<int> prev(5, 1), next(5, 0);
      int prev[5] = {1, 1, 1, 1, 1};
      int next[5] = {0};
      while (--n) {
        for (int i=0; i<5; ++i)
          for (int j=0; j<=i; ++j)
            next[i] += prev[j];

        // prev = next;
        // next.assign(5, 0);
        memcpy(prev, next, 5*sizeof(int));
        memset(next, 0, 5*sizeof(int));
      }

      int res = 0;
      for (int cnt : prev)
        res += cnt;

      return res;
    }
};


int main() {
  UFUNC(Solution::countVowelStrings);
  return 0;
}