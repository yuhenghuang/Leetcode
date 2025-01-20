#include <local_leetcode.hpp>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

    int searchInsertIndex(vector<int>& nums, int target) {
      int l = 0, r = (int) nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] < target)
          l = m + 1;
        else 
          r = m - 1;
      }

      return l;
    }
};

int main() {
  /*
  Solution sol;
  vector<int> nums = {1, 3, 5, 6};
  cout << sol.searchInsert(nums, 5) << endl;
  cout << sol.searchInsert(nums, 2) << endl;
  cout << sol.searchInsert(nums, 7) << endl;
  cout << sol.searchInsert(nums, 0) << endl;
  */

  EXECS(Solution::searchInsert);
  EXECS(Solution::searchInsertIndex);
  return 0;
}