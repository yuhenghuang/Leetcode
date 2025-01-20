#include <local_leetcode.hpp>

class Solution {
  private:
    static vector<int> squareArray() {
      vector<int> nums;
      for (int i = 1; i * i <= 10000; ++i)
        nums.push_back(i * i);

      return nums;
    }

  public:
    int numSquares(int n) {
      static const vector<int> nums = squareArray();

      vector<bool> visited(n);

      int res = 1;
      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front();
          q.pop();
          for (auto& e : nums) {
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
      static const vector<int> nums = squareArray();

      vector<int> dp(n + 1, INT_MAX);

      dp[0] = 0;
      for (int i = 0; i < n; ++i)
        for (auto& e : nums) {
          if (i + e > n) break;

          dp[i + e] = min(dp[i + e], dp[i] + 1);
        }

      return dp[n];
    }
};


int main() {
  EXECS(Solution::numSquares);
  EXECS(Solution::numSquaresDP);
  return 0;
}
