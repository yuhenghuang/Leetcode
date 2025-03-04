#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      int i = 0, j = 0;
      for (int num : nums) {
        if (num < pivot)
          ++i;
        else if (num == pivot)
          ++j;
      }

      vector<int> res(nums.size());

      auto iter1 = res.begin();
      auto iter2 = iter1 + i;
      auto iter3 = iter2 + j;

      for (int num: nums) {
        if (num < pivot)
          *iter1++ = num;
        else if (num == pivot)
          *iter2++ = num;
        else
          *iter3++ = num;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::pivotArray);
  return 0;
}