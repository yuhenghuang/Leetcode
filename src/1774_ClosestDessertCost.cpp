#include <local_leetcode.hpp>

class Solution {
  private:
    static bool dp[];

  public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
      memset(dp, 0, target * 2 + 2);

      bool flag = true;
      for (int c : baseCosts)
        if (c <= (target * 2)) {
          dp[c] = true;
          flag = false;
        }

      // return minimum base cost
      if (flag)
        return *min_element(baseCosts.begin(), baseCosts.end());

      for (int c : toppingCosts) 
        for (int i = target - 1; i >= 1; --i)
          if (dp[i]) {
              int next = i + c;
              if (next <= target * 2)
                dp[next] = true;

              next += c;
              if (next <= target * 2)
                dp[next] = true;
            }

      for (int i = 0; i <= target; ++i) {
        if (dp[target - i])
          return target - i;

        if (dp[target + i])
          return target + i;
      }

      return -1;
    }
};

bool Solution::dp[20001];


int main() {
  EXECS(Solution::closestCost);
  return 0;
}