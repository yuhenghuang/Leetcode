#include "utils.hpp"

class Solution {
  private:
    int ceilingDivide(const int& num, const int& divisor) {
      return num / divisor + (num % divisor != 0);
    }
  public:
    int smallestDivisor(vector<int>& nums, int threshold) {
      long sum = 0;
      int r = 0;
      for (const int& num : nums) {
        sum += num;
        r = max(r, num);
      }

      int l = max(sum/threshold, 1L);

      while (l<r) {
        int m = l + (r-l)/2;

        sum = 0;
        for (const int& num : nums)
          sum += ceilingDivide(num, m);

        if (sum > threshold)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }
};


int main() {
  UFUNC(Solution::smallestDivisor);
  return 0;
}