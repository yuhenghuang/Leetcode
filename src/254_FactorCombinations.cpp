#define _LL_PRINT_ARRAY_MAX_LENGTH 100
#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int i, int prod, int n, vector<int>& s, vector<vector<int>>& res) {
      if (prod == n) {
        res.push_back(s);
        return;
      }

      for (; i <= n / prod; ++i) {
        s.push_back(i);
        dfs(i, prod * i, n, s, res);
        s.pop_back();
      }
    }

  public:
    vector<vector<int>> getFactors(int n) {
      // TLE, sad

      vector<int> s;
      vector<vector<int>> res;

      dfs(2, 1, n, s, res);

      // pop [n]
      res.pop_back();

      return res;
    }
};


int main() {
  EXECS(Solution::getFactors);
  return 0;
}
