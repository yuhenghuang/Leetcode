#include "utils3.hpp"

class Solution {
  public:
    int triangleNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int res = 0;

      for (int k = nums.size() - 1; k > 1; --k) {
        int j = k - 1;
        for (int i = 0; i < k - 1; ++i) {
          while (i < j && nums[i] + nums[j] > nums[k])
            --j;

          res += k - 1 - max(i, j);
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::triangleNumber);
  return 0;
}