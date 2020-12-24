#include "utils.hpp"

class Solution {
  private:
    bool dfs(int i, int j, const string& s, const string& p) {
      if (i==s.size() && j==p.size())
        return true;
      else if (j>=p.size() || (p[j]!='*' && i>=s.size()))
        return false;

      if (p[j]=='*') {
        while (i<=s.size())
          if (dfs(i++, j+1, s, p))
            return true;
        return false;
      }
      else 
        return (p[j]=='?' || s[i]==p[j]) && dfs(i+1, j+1, s, p);
    }

  public:
    bool isMatchTLE(const string& s, const string& p) {
      return dfs(0, 0, s, p);
    }


    bool isMatch(const string& s, const string& p_raw) {
      string p;
      for (int i=0; i<p_raw.size(); ++i)
        if (i==0 || p.back()!='*' || p_raw[i]!='*')
          p.push_back(p_raw[i]);

      int m = s.size(), n = p.size();

      // vector<vector<bool>> memo(m+1, vector<bool>(n+1, false));
      bool memo[m+1][n+1];
      memset(memo, 0, (m+1)*(n+1));

      memo[0][0] = true;
      if (n>0 && p[0]=='*')
        memo[0][1] = true;
      
      for (int j=0; j<n; ++j)
        for (int i=0; i<m; ++i) {
          if (p[j]=='*') 
            memo[i+1][j+1] = memo[i+1][j] || memo[i][j] || memo[i][j+1];
          else
            memo[i+1][j+1] = memo[i][j] && (p[j]=='?' || s[i]==p[j]);
        }
      
      return memo[m][n];
    }
};


int main() {
  UFUNC(Solution::isMatch);
  return 0;
}