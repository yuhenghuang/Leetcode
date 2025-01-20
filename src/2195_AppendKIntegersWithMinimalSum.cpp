#include <local_leetcode.hpp>

class Solution {
  public:
    long long minimalKSum(vector<int>& nums, int k) {
      long long res = 0;

      set<int> s(nums.begin(), nums.end());
      s.insert(INT_MAX);

      int prev = 1;
      for (const int& curr : s) {
        int h = min(k, curr - prev);

        res += (static_cast<long long>(h) * (prev * 2 + h - 1)) / 2;

        k -= h;
        if (k <= 0)
          break;

        prev = curr + 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimalKSum);
  return 0;
}