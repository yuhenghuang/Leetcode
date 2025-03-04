#include <local_leetcode.hpp>

#define N 16


class Solution {
  private:
    static unordered_set<int> s;
    static bool helper;

    static bool init() {
      constexpr int M = 1 << N;
      
      vector<int> dp(M);

      int powers[N];
      powers[0] = 1;
      for (int i = 1; i < N; ++i) 
        powers[i] = powers[i-1] * 3;

      for (int i = 1; i < M; ++i) {
        int b = __builtin_ctz(i);
        dp[i] = dp[i ^ (1 << b)] + powers[b];
      }

      s = unordered_set<int>(dp.begin(), dp.end());

      return true;
    }

  public:
    bool checkPowersOfThree(int n) {
      return s.count(n);
    }

    bool checkPowersOfThreeMath(int n) {
      for (; n > 0; n /= 3)
        if (n % 3 == 2)
          return false;

      return true;
    }
};

unordered_set<int> Solution::s;
bool Solution::helper = Solution::init();


int main() {
  EXECS(Solution::checkPowersOfThree);
  EXECS(Solution::checkPowersOfThreeMath);
  return 0;
}