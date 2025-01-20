#include <local_leetcode.hpp>

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      // num, frequency
      unordered_map<int, int> m;

      k = min(k + 1, (int) nums.size());

      int i = 0;
      for (; i < k; ++i) {
        int& f = m[nums[i]];

        if (f != 0)
          return true;

        ++f;
      }

      for (; i < (int) nums.size(); ++i) {
        --m[nums[i - k]];

        int& f = m[nums[i]];
        if (f != 0)
          return true;

        ++f;
      }

      return false;
    }
};


int main() {
  EXECS(Solution::containsNearbyDuplicate);
  return 0;
}