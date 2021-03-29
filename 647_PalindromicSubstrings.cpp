#include "utils2.hpp"

class Solution {
  public:
    int countSubstrings(string s) {
      int n = s.size();
      
      int res = 0;
      for (int i=0; i<2*n; ++i) {
        int p = i / 2;
        int q = p + i % 2;
        
        while (p>=0 && q<n && s[p--] == s[q++])
          ++res;
      }
      
      return res;
    }

    int countSubstringsOn(string s_raw) {
      string s;
      s.reserve(s_raw.size() * 2);
      for (char c : s_raw) {
        s.push_back(c);
        s.push_back('#');
      }
      s.pop_back();

      int n = s.size();

      int res = 0;
      vector<int> dp(n);

      int cc = 0, cr = -1;
      for (int i=0; i<n; ++i) {
        int r = i < cr ? min(dp[2*cc - i], cr - i + 1) : 1;

        while (i-r >= 0 && i+r < n && s[i-r] == s[i+r])
          ++r;

        res += (r + ((i & 1) ^ 1)) >> 1;
        dp[i] = r;
        if (i+r-1 > cr) {
          cc = i;
          cr = i+r-1;
        }
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::countSubstrings);
  }
  {
    UFUNC(Solution::countSubstringsOn);
  }
  return 0;
}