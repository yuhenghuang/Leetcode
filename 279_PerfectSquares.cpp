#include "utils3.hpp"

class Solution {
public:
    int numSquares(int n) {
      vector<int> nums;
      for (int i = 1; i * i <= n; ++i)
        nums.push_back(i * i);

      vector<bool> visited(n);

      int res = 1;
      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front();
          q.pop();
          for (int e : nums) {
            int w = v + e;
            if (w > n) break;
            else if (w == n)
              return res;

            if (!visited[w]) {
              q.push(w);
              visited[w] = true;
            }
          }
        }

        ++res;
      }

      return -1;
    }

    int numSquaresDP(int n) {
      vector<int> nums;
      for (int i = 1; i * i <= n; ++i)
        nums.push_back(i * i);

      vector<int> dp(n + 1, INT_MAX);

      dp[0] = 0;
      for (int i = 0; i < n; ++i)
        for (int e : nums) {
          if (i + e > n) break;

          dp[i + e] = min(dp[i + e], dp[i] + 1);
        }

      return dp[n];
    }
};


int main() {
  UFUNCS(Solution::numSquares);
  UFUNCS(Solution::numSquaresDP);
  return 0;
}