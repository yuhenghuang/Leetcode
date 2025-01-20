#include "utils3.hpp"

template <typename T>
constexpr const T &max(const T &a, const T &b, const T &c) {
  return max(max(a, b), c);
}

template <typename T>
constexpr const T &min(const T &a, const T &b, const T &c) {
  return min(min(a, b), c);
}

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();

      vector<int> left_max(n), left_min(n), right_max(n), right_min(n);

      int res=INT_MIN;
      for (int i=0; i<n; ++i) {
        res = max(res, nums[i]);
        if (i==0 || nums[i]==0) {
          left_max[i] = nums[i];
          left_min[i] = nums[i];
        }
        else {
          left_max[i] = max(nums[i], nums[i]*left_max[i-1], nums[i]*left_min[i-1]);
          left_min[i] = min(nums[i], nums[i]*left_max[i-1], nums[i]*left_min[i-1]);
        }
      }

      for (int i=n-1; i>=0; --i) {
        if (i==n-1 || nums[i]==0) {
          right_max[i] = nums[i];
          right_min[i] = nums[i];
        }
        else {
          right_max[i] = max(nums[i], nums[i]*right_max[i+1], nums[i]*right_min[i+1]);
          right_min[i] = min(nums[i], nums[i]*right_max[i+1], nums[i]*right_min[i+1]);
        }
      }

      for (int i=0; i<n-1; ++i)
        res = max(res, left_max[i]*right_max[i+1], left_min[i]*right_min[i+1]);

      return res;
    }
};

int main() {
  UFUNCS(Solution::maxProduct);
  return 0;
}