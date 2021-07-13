#include "utils2.hpp"


class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      int n = s.size();

      //ascii characters...
      int s2t[256];
      int t2s[256];
      memset(s2t, -1, sizeof(s2t));
      memset(t2s, -1, sizeof(t2s));

      for (int i = 0; i < n; ++i) {
        int is = s[i], it = t[i];
        if (s2t[is] < 0)
          s2t[is] = it;

        if (t2s[it] < 0)
          t2s[it] = is;

        if (s2t[is] != it || t2s[it] != is)
          return false;
      }


      return true;
    }
};


int main() {
  UFUNC(Solution::isIsomorphic);
  return 0;
}