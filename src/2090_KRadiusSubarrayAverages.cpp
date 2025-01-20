#include "utils3.hpp"

class Solution {
  public:
    vector<int> getAverages(vector<int>& nums, const int k) {
      if (k == 0)
        return nums;

      int n = nums.size();
      vector<int> res(n, -1);
      if (k * 2 >= n)
        return res;

      long sum = 0;
      for (int i = 0; i <= 2 * k; ++i)
        sum += nums[i];

      res[k] = sum / (2*k + 1);
      for (int i = k + 1; i + k < n; ++i) {
        sum += nums[i+k] - nums[i-k-1];
        res[i] = sum / (2*k + 1);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::getAverages);
  return 0;
}