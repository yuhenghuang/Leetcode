#include <local_leetcode.hpp>

class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> memo(amount + 1, INT_MAX);
      
      memo[0] = 0;
      for (int i = 1; i <= amount; ++i) 
        for (const int& coin : coins) 
          if (i - coin >= 0 && memo[i - coin] != INT_MAX) 
            memo[i] = min(memo[i], memo[i-coin] + 1);

      return memo[amount]==INT_MAX ? -1 : memo[amount];
    }
};


int main() {
  EXECS(Solution::coinChange);
  return 0;
}