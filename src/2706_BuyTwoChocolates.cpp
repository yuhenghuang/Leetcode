#include <local_leetcode.hpp>

class Solution {
  public:
    int buyChoco(vector<int>& prices, int money) {
      int first = min(prices[0], prices[1]);
      int second = max(prices[0], prices[1]);

      for (int i = 2; i < prices.size(); ++i) {
        int p = prices[i];
        if (p <= first) {
          second = first;
          first = p;
        }
        else if (p < second)
          second = p;
      }

      int cost = first + second;
      return cost > money ? money : (money - cost);
    }
};


int main() {
  EXECS(Solution::buyChoco);
  return 0;
}