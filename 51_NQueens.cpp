#include "utils.hpp"

class Solution {
  private:
    void dfs(int i, vector<string>& s, vector<vector<string>>& res, 
             int n, vector<bool>& clm, vector<bool>& diag, vector<bool>& anti_diag) {
      //...
      if (i==n) {
        res.push_back(s);
        return;
      }

      s.push_back(string(n, '.'));
      for (int j=0; j<n; ++j) {
        if (clm[j] || diag[n-1-i+j] || anti_diag[i+j]) 
          continue;

        clm[j] = true;
        diag[n-1-i+j] = true;
        anti_diag[i+j] = true;
        s.back()[j] = 'Q';

        dfs(i+1, s, res, n, clm, diag, anti_diag);

        s.back()[j] = '.';
        clm[j] = false;
        diag[n-1-i+j] = false;
        anti_diag[i+j] = false;
      }
      s.pop_back();
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<bool> clm(n), diag(2*n-1), anti_diag(2*n-1);

      vector<vector<string>> res;
      vector<string> s;
      s.reserve(n);
      
      dfs(0, s, res, n, clm, diag, anti_diag);

      return res;
    }
};


int main() {
  UFUNC(Solution::solveNQueens);
  return 0;
}