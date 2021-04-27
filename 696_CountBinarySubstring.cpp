#include "utils2.hpp"

class Solution {
  public:
    int countBinarySubstrings(string s) {
      int c[2];
      c[0] = s[0] == '0';
      c[1] = 1 - c[0];
      
      int res = 0;
      for (int i = 1; i < s.size(); ++i) {
        int idx = s[i] - '0';
        if (s[i] != s[i-1]) 
          c[idx] = 0;
        
        ++c[idx];
        if (c[idx] <= c[1-idx])
          ++res;
        
      }
      
      return res;
    }

    int countBinarySubstringsFast(string s) {
      int prev = 0, curr = 1;
      int res = 0;

      for (int i = 1; i < s.size(); ++i) {
        if (s[i-1] == s[i])
          ++curr;
        else {
          res += min(prev, curr);
          prev = curr;
          curr = 1;
        }
      }

      return res + min(prev, curr);
    }
};


int main() {
  {
    UFUNC(Solution::countBinarySubstrings);
  }
  {
    UFUNC(Solution::countBinarySubstringsFast);
  }
  return 0;
}