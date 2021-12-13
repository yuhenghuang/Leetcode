#include "utils3.hpp"

class Solution {
  private:
    bool is_subseq(string& s, string& p) {
      int j = 0;

      for (int i = 0; i < s.size(); ++i) {
        // better to have early stop?
        if (i + p.size() > j + s.size())
          break;

        if (s[i] == p[j])
          ++j;

        if (j == p.size())
          return true;
      }

      return false;
    }

  public:
    int maximumRemovals(string s_orig, string p, vector<int>& removable) {
      string s;
      int l = 0, r = removable.size();
      while (l < r) {
        int m = l + (r - l) / 2 + (r - l) % 2;

        // memcpy is quite efficient
        s = s_orig;

        for (int i = 0; i < m; ++i)
          s[removable[i]] = '*';

        if (!is_subseq(s, p))
          r = m - 1;
        else
          l = m;
      }

      return l;
    }
};


int main() {
  UFUNCS(Solution::maximumRemovals);
  return 0;
}