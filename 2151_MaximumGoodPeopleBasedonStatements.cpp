#include <local_leetcode.hpp>

class Solution {
  private:
    int bits;

    void dfs(int i, vector<vector<int>>& statements) {
      bits |= 1 << i;

      for (int j = 0; j < statements.size(); ++j)
        if (statements[i][j] == 1 && ((bits >> j) & 1) == 0)
          dfs(j, statements);
    }

  public:
    int maximumGood(vector<vector<int>>& statements) {
      const int n = statements.size();

      // given person i is good, good_bits[i] is bits of good people
      vector<int> good_bits(n);
      for (int i = 0; i < n; ++i) {
        bits = 0;
        dfs(i, statements);
        good_bits[i] = bits;
      }

      // given the statement of person i to be true, bad_bits[i] is bits of bad people
      vector<int> bad_bits(n);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          if (statements[i][j] == 0)
            bad_bits[i] |= 1 << j;

      // (good bit, bad bit)
      unordered_map<int, int> m;
      for (int i = 0; i < n; ++i) {
        int gb = good_bits[i];
        int bb = 0;
        for (int j = 0; j < n; ++j)
          if ((gb >> j) & 1)
            bb |= bad_bits[j];

        // if good bit and bad bit are not self-contradictory
        if ((gb & bb) == 0)
          m[gb] = bb;
      }

      const int N = 1 << n;

      // non-negative: bits of combination i of good people and dp[i] of bad people
      // -1 : no feasible combination
      vector<int> dp(N, -1);
      dp[0] = 0;

      int res = 0;
      for (int i = 0; i < N; ++i)
        if (dp[i] >= 0) {
          res = max(res, __builtin_popcount(i));

          for (const auto& [gb, bb] : m)
            if ((i & gb) == 0 and (i & bb) == 0 and (dp[i] & gb) == 0)
              dp[i | gb] = dp[i] | bb;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumGood);
  return 0;
}