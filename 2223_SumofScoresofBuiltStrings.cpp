#include <local_leetcode.hpp>

class Solution {
  public:
    long long sumScores(string s) {
      // z-algorithm
      // find the longest prefix substring at each index

      int n = s.size();

      vector<int> z(n);

      z[0] = n;

      // [l, r) longest prefix substr starting at l
      int l, r = 0;

      for (int i = 1; i < n; ++i) {
        // i is outside of [l, r)
        if (i >= r) {
          l = i;
          for (r = i; r < n && s[r] == s[r - l]; ++r);

          z[i] = r - l;
        }
        else {
          // [0, r - l) == [l, r)
          int k = i - l;

          // z[k] doesn't get outside of r - l
          if (z[k] < r - i)
            z[i] = z[k];
          else {
            l = i;
            for (; r < n && s[r] == s[r - l]; ++r);

            z[i] = r - l;
          }
        }
      }

      return reduce(z.begin(), z.end(), 0LL);
    }
};


int main() {
  EXECS(Solution::sumScores);
  return 0;
}