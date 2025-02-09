#include <local_leetcode.hpp>

class Solution {
  public:
    long long countBadPairs(vector<int>& nums) {
      // num, count
      unordered_map<int, int> m;

      long long res = 0;
      for (int i = 0 ; i < (int) nums.size(); ++i) {
        int num = nums[i] - i;

        auto iter = m.find(num);

        res += i - (iter == m.end() ? 0: iter->second);

        ++m[num];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countBadPairs);
  return 0;
}