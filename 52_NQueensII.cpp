#include "utils2.hpp"

class Solution {
  private:
    int res;

    void dfs(int i, int n,
             vector<bool>& clm, vector<bool>& diag, vector<bool>& antiDiag) {
      // ...
      // search reaches the end of rows
      // end condition
      if (i == n) {
        ++res;
        return;
      }

      // loop over each column `j` in row `i`
      for (int j = 0; j < n; ++j) {
        if (clm[j] || diag[j-i + n-1] || antiDiag[j+i])
          continue;
        
        clm[j] = true;
        diag[j-i + n-1] = true;
        antiDiag[j+i] = true;

        dfs(i+1, n, clm, diag, antiDiag);
        
        clm[j] = false;
        diag[j-i + n-1] = false;
        antiDiag[j+i] = false;
      }
    }

  public:
    int totalNQueens(int n) {
      // reset result
      res = 0;

      // indicators for columns, diagonals, and anti-diagonals
      vector<bool> clm(n), diag(2*n + 1), antiDiag(2*n + 1);
      dfs(0, n, clm, diag, antiDiag);

      return res;
    }
};


int main() {
  UFUNC(Solution::totalNQueens);
  return 0;
}