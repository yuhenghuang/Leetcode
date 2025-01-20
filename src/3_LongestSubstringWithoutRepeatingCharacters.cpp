#include <local_leetcode.hpp>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wchar-subscripts"


class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      // lowercase letters only

      int res = 0;

      int count[26] = {0};
      int j = 0;
      for (int i = 0; i < s.size(); ++i) {
        int k = s[i] - 'a';
        ++count[k];

        while (count[k] > 1)
          --count[s[j++] - 'a'];

        res = max(res, i - j + 1);
      }

      return res;
    }

    int lengthOfLongestSubstringOld(string s) {
      int n = s.length();

      int res = 0;

      int cnt[256] = {0};
      int l = 0, r = 0;
      while (r<n) {
        while (r<n && !cnt[s[r]]) 
          ++cnt[s[r++]];

        res = max(res, r-l);

        while (r<n && s[l]!=s[r]) 
          --cnt[s[l++]];

        --cnt[s[l++]];
      }

      return res;
    }
};


#pragma clang diagnostic pop

int main() {
  EXECS(Solution::lengthOfLongestSubstringOld);
  EXECS(Solution::lengthOfLongestSubstring);
  return 0;
}