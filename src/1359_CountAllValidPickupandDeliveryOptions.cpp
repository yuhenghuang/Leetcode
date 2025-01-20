#include <local_leetcode.hpp>

class Solution {
  public:
    int countOrders(int n) {
      static constexpr uint64_t mod = 1e9 + 7;

      uint64_t res = 1;

      for (int i = 1; i <= n; ++i)
        res = (res * (i * 2 - 1) * i) % mod;

      return res;
    }
};


int main() {
  EXECS(Solution::countOrders);
  return 0;
}