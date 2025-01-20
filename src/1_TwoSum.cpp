#include "utils3.hpp"

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> m;
      unordered_map<int, int>::iterator iter;
      for (int i = 0; i < nums.size(); ++i) {
        iter = m.find(nums[i]);
        if (iter != m.end())
          return {iter->second, i};

        m[target - nums[i]] = i;
      }

      return {-1, -1};
    }
};


int main() {
  UFUNCS(Solution::twoSum);
  return 0;
}