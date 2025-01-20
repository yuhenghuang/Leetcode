#include <local_leetcode.hpp>

class Solution {
  public:
    long long getDescentPeriods(vector<int>& prices) {
      long l = 1;
      long res = 1;
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i-1] == prices[i] + 1)
          ++l;
        else
          l = 1;

        res += l;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getDescentPeriods);
  return 0;
}