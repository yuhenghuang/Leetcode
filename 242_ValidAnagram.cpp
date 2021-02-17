#include "utils2.hpp"

class Solution {
  public:
    bool isAnagram(string s, string t) {
      int n = s.size();
      if (t.size() != n)
        return false;

      int cnt_s[26], cnt_t[26];
      memset(cnt_s, 0, 26*sizeof(int));
      memset(cnt_t, 0, 26*sizeof(int));

      for (int i=0; i<n; ++i) {
        ++cnt_s[s[i]-'a'];
        ++cnt_t[t[i]-'a'];
      }

      for (int i=0; i<26; ++i)
        if (cnt_s[i] != cnt_t[i])
          return false;

      return true;
    }
};


int main() {
  UFUNC(Solution::isAnagram);
  return 0;
}