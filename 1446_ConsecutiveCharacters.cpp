#include "utils.hpp"

class Solution {
  public:
    int maxPower(string s) {
      int n = s.size();
      if (n<2) return n;
      int res = 1, curr = 1;
      for (int i=1; i<n; ++i) {
        if (s[i-1]==s[i])
          ++curr;
        else
          curr = 1;

        res = max(res, curr);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::maxPower);
  return 0;
}