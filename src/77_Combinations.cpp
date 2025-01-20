#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int i, int n, int k, vector<int>& s, vector<vector<int>>& res) {
      if (s.size() == k) {
        res.push_back(s);
        return;
      }

      for (; i <= n; ++i) {
        s.push_back(i);

        dfs(i + 1, n, k, s ,res);

        s.pop_back();
      }
    }

  public:
    vector<vector<int>> combine(int n, int k) {
      // stack
      vector<int> s;

      vector<vector<int>> res;

      dfs(1, n, k, s, res);

      return res;
    }
};


int main() {
  EXECS(Solution::combine);
  return 0;
}