#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(int i, int n, vector<bool>& used, vector<int>& s, vector<int>& res) {
      // early stop
      if (!res.empty())
        return;
      else if (i == s.size()) {
        res = s;
        return;
      }
      else if (s[i] >= 0) {
        dfs(i+1, n, used, s, res);
        return;
      }

      for (int k = min((int)s.size() - 1 - i, n); k > 1; --k)
        if (!used[k] && s[i+k] < 0) {
          used[k] = true;
          s[i] = s[i+k] = k;

          dfs(i+1, n, used, s, res);

          s[i] = s[i+k] = -1;
          used[k] = false;
        }

      if (!used[1]) {
        used[1] = true;
        s[i] = 1;

        dfs(i+1, n, used, s, res);

        s[i] = -1;
        used[1] = false;
      }
    }

  public:
    vector<int> constructDistancedSequence(int n) {
      vector<int> s(n*2 - 1, -1);
      vector<int> res;
      vector<bool> used(n + 1);s

      dfs(0, n, used, s, res);

      return res;
    }
};


int main() {
  EXECS(Solution::constructDistancedSequence);
  return 0;
}