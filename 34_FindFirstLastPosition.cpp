#include "utils2.hpp"

class Solution {
  private:
    int findFirst(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      while (l < r) {
        int m = l + (r-l) / 2;

        if (nums[m] < target)
          l = m + 1;
        else
          r = m;
      }

      return nums[l] == target ? l : -1;
    }

    int findLast(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      while (l < r) {
        int m = l + (r-l) / 2 + (r-l) % 2;

        if (nums[m] > target)
          r = m - 1;
        else
          l = m;
      }

      return nums[r] == target ? r : -1;
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.empty()) return {-1, -1};

      vector<int> res;
      res.push_back(findFirst(nums, target));
      res.push_back(findLast(nums, target));

      return res;
    }
};


int main() {
  UFUNC(Solution::searchRange);
  return 0;
}