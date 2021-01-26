#include "utils.hpp"

class Solution {
  public:
    string longestPalindromeOn(string s) {
      string sp;
      for (char c : s) {
        sp.push_back(c);
        sp.push_back('#');
      }
      sp.pop_back();
      
      // center of current largest palindrome that contains index
      int c=0;
      // right boundary of the palindrome
      int r=-1;

      int n = sp.size();
      int p[n];
      memset(p, 0, n*sizeof(int));

      int radius;
      int st=0, le=1;
      for (int i=0; i<n; ++i) {
        if (i>r)
          radius = 0;
        else
          radius = min(p[c*2-i], r-i);

        while (i+radius+1<n && i-radius-1>=0 && sp[i+radius+1]==sp[i-radius-1])
          ++radius;

        p[i] = radius;

        int len = (i+radius)/2 - (i-radius+1)/2 + 1;
        if (len > le) {
          st = (i-radius+1)/2;
          le = len;
        }

        // r is always on #
        if (i+radius-1>r) {
          c = i;
          r = i+radius-1;
        }
      }

      return s.substr(st, le);
    }

    string longestPalindrome(string s) {
      int n = s.size();
      bool memo[n][n];
      memset(memo, 0, n*n);
      memo[0][0] = true;

      int st=0, le=1;
      for (int i=1; i<n; ++i) {
        memo[i][i] = true;
        memo[i-1][i] = s[i-1]==s[i];
        if (le<2 && memo[i-1][i]) {
          le = 2;
          st = i-1;
        }
      }
      for (int l=2; l<n; ++l)
        for (int i=0; i+l<n; ++i) {
          memo[i][i+l] = memo[i+1][i+l-1] && s[i]==s[i+l];
          if (l>=le && memo[i][i+l]) {
            le = l+1;
            st = i;
          }
        }

      return s.substr(st, le);
    }
};


int main() {
  {
    UFUNC(Solution::longestPalindrome);
  }
  {
    UFUNC(Solution::longestPalindromeOn);
  }
  return 0;
}