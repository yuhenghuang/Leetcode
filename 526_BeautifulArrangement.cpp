#include "utils.hpp"

class Solution {
  private:
    int n, res;

    void dfs(int i, vector<bool>& seen, const vector<vector<bool>>& divisors) {
      if (i==n) 
        ++res;

      for (int j=0; j<n; ++j) {
        if (!seen[j] && divisors[i][j]) {
          seen[j] = true;
          dfs(i+1, seen, divisors);
          seen[j] = false;
        }
      }
    }

  public:
    int countArrangement(int n) {
      vector<vector<bool>> divisors(n, vector<bool>(n, false));
      for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
          if (i % j==0) {
            divisors[i-1][j-1] = true;
            divisors[j-1][i-1] = true;
          }

      vector<bool> seen(n, false);

      this->n = n;
      res = 0;
      dfs(0, seen, divisors);

      return res;
    }
};


int main() {
  UFUNC(Solution::countArrangement);
  return 0;
}