#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<char, int> ci_t;

    // i, j, k
    static int dp[100][100][101];

    int length(int f) {
      if (f <= 0)
        return 0;
      else if (f == 1)
        return 1;
      else if (f < 10)
        return 2;
      else if (f < 100)
        return 3;
      else
        return 4; // e.g. a100
    }


    int dfs(int i, int j, int k, const vector<ci_t>& arr) {
      if (i > j)
        return 0;
      else if (dp[i][j][k] >= 0)
        return dp[i][j][k];

      // one identical character only
      if (i == j)
        return dp[i][j][k] = length(arr[i].second - k);
      

      int res = INT_MAX;

      for (int m = i; m < j; ++m) {
        // [i, m] and [m+1, j]
        for (int p = 0; p <= k; ++p)
          res = min(res, dfs(i, m, p, arr) + dfs(m+1, j, k - p, arr));

        
      }


      return dp[i][j][k] = res;
    }

  public:
    int getLengthOfOptimalCompression(string s, int k) {
      // unfinished

      /* cases to reduce length by deleting characters

        1. a1 -> '' (a0) by deleting 1
        2. ax -> a by deleting x - 1, x in [2, 9]
        3. axx -> a9 by deleting xx - 9, xx in

        but!! new consecutive characters might be formed after deletiong!!

        so we can only solve it by DP, not greedy
      */

      vector<ci_t> arr;
      arr.emplace_back(s.front(), 1);

      for (int i = 1; i < s.size(); ++i)
        if (s[i] == s[i-1])
          ++arr.back().second;
        else
          arr.emplace_back(s[i], 1);

      int n = arr.size();

      // reset dp
      for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
          for (int m = 0; m <= k; ++m)
            dp[i][j][m] = -1;

      return dfs(0, n-1, k, arr);
    }
};

int Solution::dp[100][100][101];


int main() {
  EXECS(Solution::getLengthOfOptimalCompression);
  return 0;
}