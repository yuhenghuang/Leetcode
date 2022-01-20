#include <local_leetcode.hpp>

class Solution {
  public:
    int integerReplacement(int n) {
      unordered_map<long, int> dp;
      dp[n] = 0;

      queue<pair<long, int>> q;
      q.emplace(n, 0);

      while (!q.empty()) {
        auto [v, ops] = q.front();
        q.pop();

        if (v == 1)
          continue;

        long w;
        if (v & 1) {
          w = v + 1;
          if (dp.find(w) == dp.end() || ops + 1 < dp[w]) {
            dp[w] = ops + 1;
            q.emplace(w, ops + 1);
          }

          w = v - 1;
          if (dp.find(w) == dp.end() || ops + 1 < dp[w]) {
            dp[w] = ops + 1;
            q.emplace(w, ops + 1);
          }
        }
        else {
          w = v >> 1;
          if (dp.find(w) == dp.end() || ops + 1 < dp[w]) {
            dp[w] = ops + 1;
            q.emplace(w, ops + 1);
          }
        }


      }

      return dp[1]; 
    }

    int integerReplacementFast(int n) {
      int res = 0;

      while (n > 1) {
        if ((n & 1) == 0)
          n >>= 1;
        else if (((n >> 1) & 1) == 0 || (n >> 1) == 1) // 0b....01 or 0b11
          n ^= 1;
        else
          ++n;

        ++res;
      }

      return res;
    }

    int integerReplacementWrong(int _n) {
      // wrong answer...

      long n = _n;

      int res = 0;

      while (n > 0) {
        if (n & 1) {
          if (((n >> 1) & 1) && ((n >> 2) & 1))
            n += 1;
          else
            n ^= 1;
        } 
        else {
          n >>= 1;
        }

        ++res;
      }

      return res - 1;
    }
};


int main() {
  EXECS(Solution::integerReplacement);
  EXECS(Solution::integerReplacementFast);
  EXECS(Solution::integerReplacementWrong);
  return 0;
}