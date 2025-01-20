#include <local_leetcode.hpp>

class Solution {
  private:
    bool compareSubstr(const string& p, const string& s, int i) {
      for (int j = 0; j < (int) p.size(); ++i, ++j)
        if (s[i] != p[j])
          return false;

      return true;
    }

  public:
    int strStr(string haystack, string needle) {
      int n = haystack.size();
      int m = needle.size();

      if (n < m)
        return -1;

      constexpr size_t mod = 1e10 + 7;
      constexpr size_t factor = 11;

      size_t multiplier = 1;
      for (int k = 0 ; k < m; ++k)
        multiplier = (multiplier * factor) % mod;

      size_t hash_orig = 0, hash_val = 0;

      int i = 0;
      for (; i < m; ++i) {
        hash_orig = (hash_orig * factor + static_cast<size_t>(needle[i] - 'a' + 1)) % mod;
        hash_val = (hash_val * factor + static_cast<size_t>(haystack[i] - 'a' + 1)) % mod;
      }

      // compare (sub)strings only when hash values are identical
      if (hash_orig == hash_val && compareSubstr(needle, haystack, 0))
        return 0;

      for (; i < n; ++i) {
        // update hash value by
        // multiplying hash value by factor
        // removing hash value of first letter
        // adding hash value of new last letter
        hash_val = (hash_val * factor - static_cast<size_t>(haystack[i - m] - 'a' + 1) * multiplier + mod + static_cast<size_t>(haystack[i] - 'a' + 1)) % mod;

        if (hash_orig == hash_val && compareSubstr(needle, haystack, i - m + 1))
          return i - m + 1;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::strStr);
  return 0;
}