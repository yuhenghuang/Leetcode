#include "utils2.hpp"

class Solution {
  private:
    bool pred(unordered_map<char, int>& m, int t) {
      for (const auto& p : m)
        if (p.second > t)
          return true;

      return false;
    }

  public:
    int balancedString(string s) {
      unordered_map<char, int> m;
      for (char c : s)
        ++m[c];

      int n = s.size();
      int j = 0;

      int res = n;
      for (int i=0; i<n; ++i) {
        while (j<n && pred(m, n / 4)) {
          --m[s[j]];
          ++j;
        }

        if (!pred(m, n / 4))
          res = min(res, j-i);

        ++m[s[i]];
      }

      return res;
    }

    int balancedStringWrong(string s) {
      // Wrong answer

      int count[26];
      memset(count, 0, 26*sizeof(int));
      
      int n = s.size();
      int target = n/4;
      int i = 0, j = n-1;

      while (i < n && count[s[i] - 'A'] < target) {
        ++count[s[i] - 'A'];
        ++i;
      }
      
      int res = j - i + 1;
      
      for (--i; i>=0; --i) {
        --count[s[i] - 'A'];
        while (j >= i && count[s[j] - 'A'] < target) {
          ++count[s[j] - 'A'];
          --j;
        }

        res = min(res, j - i + 1);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::balancedString);
  return 0;
}