#include "utils3.hpp"

class Solution {
  private:
    int preprocess(vector<int>& nums, int (&inc)[6], int (&dec)[6]) {
      int sum = 0;
      for (int num : nums) {
        sum += num;
        ++inc[6 - num];
        ++dec[num - 1];
      }

      return sum;
    }

  public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
      int inc1[6] = {0};
      int dec1[6] = {0};
      int inc2[6] = {0};
      int dec2[6] = {0};

      int sum1 = preprocess(nums1, inc1, dec1);
      int sum2 = preprocess(nums2, inc2, dec2);

      if (sum1 == sum2)
        return 0;

      // better to implement by passing arguments to function
      if (sum1 > sum2) {
        swap(sum1, sum2);
        swap(inc1, inc2);
        swap(dec1, dec2);
      }

      int res = 0;
      int i = 5, j = 5;
      while (i > 0 || j > 0) {
        if (i > 0 && inc1[i] == 0) {
          --i;
          continue;
        }

        if (j > 0 && dec2[j] == 0) {
          --j;
          continue;
        }

        if (i > j) {
          sum1 += i;
          --inc1[i];
        }
        else {
          sum2 -= j;
          --dec2[j];
        }

        ++res;
        if (sum1 >= sum2)
          return res;
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::minOperations);
  return 0;
}