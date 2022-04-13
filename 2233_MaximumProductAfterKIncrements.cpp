#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> pii_t;

  public:
    int maximumProduct(vector<int>& nums, int k) {
      constexpr long long mod = 1e9 + 7;

      sort(nums.begin(), nums.end(), greater<>());

      // num, frequency in a strictly decreasing monotonic stack
      stack<pii_t> s;
      s.emplace(INT_MAX, 0);

      for (const int& num : nums) {
        if (num < s.top().first)
          s.emplace(num, 1);
        else
          ++s.top().second;
      }

      while (s.size() > 1 && k > 0) {
        pii_t p = s.top();
        s.pop();

        auto& [i, f] = s.top();

        // increment all p.fisrt to i
        // division to avoid overflow
        if (i - p.first <= k / p.second) {
          k -= (i - p.first) * p.second;

          f += p.second;
        }
        // not enough k to do so
        else {
          // largest incremental can be made
          int inc = k / p.second;

          // remainders used to further increment by 1
          k -= inc * p.second;

          s.emplace(p.first + inc + 1, k);
          s.emplace(p.first + inc, p.second - k);

          // all k operations used up
          k = 0;
        }
      }

      long long res = 1;
      while (s.size() > 1) {
        auto& [i, f] = s.top();

        for (int j = 0; j < f; ++j)
          res = (res * i) % mod;

        s.pop();
      }

      return res % mod;
    }
};


int main() {
  EXECS(Solution::maximumProduct);
  return 0;
}