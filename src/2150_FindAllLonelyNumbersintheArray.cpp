#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findLonely(vector<int>& nums) {
      int n = nums.size();

      sort(nums.begin(), nums.end());

      vector<int> res;

      int prev = -3;
      int count = 0;
      int curr = -2;
      for (int i = 0; i < n; ++i) {
        if (curr < nums[i]) {
          if (count == 1 && prev + 1 < curr && curr + 1 < nums[i])
            res.push_back(curr);

          prev = curr;
          curr = nums[i];
          count = 1;
        }
        else 
          ++count;
      }

      if (count == 1 && prev + 1 < curr)
        res.push_back(curr);

      return res;
    }
};


int main() {
  EXECS(Solution::findLonely);
  return 0;
}