#include <local_leetcode.hpp>

class Solution {
  public:
    int numDecodings(string s) {
      int n = s.size();
      int memo[n+1];
      memset(memo, 0, (n+1)*sizeof(int));
      memo[0] = 1;

      for (int i=0; i<n; ++i) {
        if (s[i]=='0') {
          if (i==0 || (s[i-1]!='1' && s[i-1]!='2'))
            break;
        }
        else
          memo[i+1] = memo[i];

        if (i>0 && (s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7')))
          memo[i+1] += memo[i-1];
      }

      return memo[n];
    }
};


int main() {
  EXECS(Solution::numDecodings);
  return 0;
}
