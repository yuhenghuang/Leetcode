#include "utils2.hpp"

class Solution {
  public:
    int maximumGap(vector<int>& nums) {
      int n = nums.size();

      // n == 1 will cause divide-by-zero error in this algorithm, i.e. (n - 1) buckets
      if (n < 2)
        return 0;

      // find min and max values in the array
      int numMin = INT_MAX, numMax = 0;
      for (int num : nums) {
        if (num < numMin)
          numMin = num;
        if (num > numMax)
          numMax = num;
      }

      // find the proper bucket size where there are
      // (n - 1) buckets for (numMax - numMin + 1) elements
      int bucketSize = (numMax - numMin) / (n - 1) + 1;

      vector<int> bucketMins(n-1, INT_MAX);
      vector<int> bucketMaxs(n-1, 0);

      // update min and max values in the corresponding bucket
      for (int num : nums) {
        int bucketIndex = (num - numMin) / bucketSize;

        if (num < bucketMins[bucketIndex])
          bucketMins[bucketIndex] = num;

        if (num > bucketMaxs[bucketIndex])
          bucketMaxs[bucketIndex] = num;
      }

      // initialize variables for the loop
      // the values are guaranteed to be valid in bucket 0

      // result
      int res = bucketMaxs[0] - bucketMins[0];

      // current max value
      int currMax = bucketMaxs[0];

      for (int i = 1; i < n - 1; ++i)
        // only update result in non-empty bucket
        if (bucketMaxs[i] != 0) {
          res = max(res, bucketMins[i] - currMax);
          currMax = bucketMaxs[i];
        }

      return res;
    }
};


int main() {
  UFUNC(Solution::maximumGap);
  return 0;
}