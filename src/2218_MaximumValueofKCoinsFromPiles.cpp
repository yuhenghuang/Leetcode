#include <local_leetcode.hpp>

class Solution {
  public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
      // time: O(nk)
      // memory: O(2k)

      vector<int> prev(k + 1, -1);
      prev[0] = 0;

      // initialize curr with no coin from pile
      vector<int> curr = prev;

      for (auto& pile : piles) {
        int sum = 0; // prefix sum

        for (int i = 1; i <= pile.size(); ++i) {
          sum += pile[i-1];

          for (int j = 0; j + i <= k && prev[j] >= 0; ++j)
            curr[j + i] = max(curr[j + i], prev[j] + sum);
        }

        prev = curr;
      }

      return curr[k];
    }


    int maxValueOfCoinsMemory(vector<vector<int>>& piles, int k) {
      // time: O(nk)
      // memory: O(k)

      vector<int> dp(k + 1);

      int n = 0; // num of max coins
      for (auto& pile : piles) {
        // prefix sum
        for (int i = 1; i < pile.size(); ++i)
          pile[i] += pile[i-1];

        int m = min(k, n + static_cast<int>(pile.size())); // num of max coins after collecting pile

        for (int i = m; i > 0; --i) 
          for (int j = max(i - n, 1); j <= pile.size() && j <= i; ++j)
            dp[i] = max(dp[i], dp[i - j] + pile[j - 1]);

        n = m;
      }

      return dp[k];
    }
};


int main() {
  EXECS(Solution::maxValueOfCoins);
  EXECS(Solution::maxValueOfCoinsMemory);
  return 0;
}