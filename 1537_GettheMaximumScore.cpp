#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr long long mod = 1e9 + 7;

  public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();

      long long res = 0, sum1 = 0, sum2 = 0;

      int i = 0, j = 0;
      while (i < m || j < n) {
        if (i == m)
          sum2 += nums2[j++];
        else if (j == n)
          sum1 += nums1[i++];
        else {
          if (nums1[i] < nums2[j])
            sum1 += nums1[i++];
          else if (nums1[i] > nums2[j])
            sum2 += nums2[j++];
          else {
            res += max(sum1, sum2) + nums1[i];

            sum1 = 0;
            sum2 = 0;

            ++i;
            ++j;
          }
        }
      }

      res += max(sum1, sum2);

      return res % mod;
    }
};


int main() {
  EXECS(Solution::maxSum);
  return 0;
}