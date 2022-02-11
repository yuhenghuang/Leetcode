#include <local_leetcode.hpp>

class Solution {
  public:
    string subStrHash(string s, int _power, int _modulo, int k, int _hashValue) {
      int n = s.size();

      size_t p = _power;
      size_t mod = _modulo;
      size_t target = _hashValue;

      size_t val = (s[n - k] - 'a' + 1) % mod; // hash value
      size_t p_k_1 = 1; // p ^ (k - 1)

      for (int i = n - k + 1; i < n; ++i) {
        p_k_1 = (p_k_1 * p) % mod;
        val = (val + (s[i] - 'a' + 1) * p_k_1) % mod;
      }

      int res = 0;

      if (val == target)
        res = n - k;

      for (int i = n - k - 1; i >= 0; --i) {
        val = ((val + mod - ((s[i+k] - 'a' + 1) * p_k_1) % mod) * p % mod + (s[i] - 'a' + 1)) % mod;

        if (val == target)
          res = i;
      }

      return s.substr(res, k);
    }
};


int main() {
  EXECS(Solution::subStrHash);
  return 0;
}