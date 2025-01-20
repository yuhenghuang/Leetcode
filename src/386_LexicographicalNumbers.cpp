#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int i, int n, vector<int>& res) {
      if (i <= n)
        res.push_back(i);
      else
        return;

      i *= 10;
      for (int j = 0; j < 10; ++j)
        dfs(i + j, n, res);
    }

  public:
    vector<int> lexicalOrder(int n) {
      vector<int> res;
      res.reserve(n);

      if (n < 10) {
        res.resize(n);
        iota(res.begin(), res.end(), 1);

        return res;
      }

      for (int i = 1; i < 10; ++i)
        dfs(i, n, res);

      return res;
    }
};


int main() {
  EXECS(Solution::lexicalOrder);
  return 0;
}