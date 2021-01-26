#include <bitset>
#include "utils2.hpp"

class Solution {
  public:
    bool kLengthApart(vector<int>& nums, int k) {
      int d = 0;
      for (int num : nums) {
        if (num) {
          if (d>0)
            return false;

          d = k;
        }
        else
          --d;
      }

      return true;
    }

    bool kLengthApartBit(vector<int>& nums, int k) {
      // TLE
      
      bitset<(size_t)1e5> x;

      for (int num : nums) {
        x <<= 1;
        if (num)
          x.set(0);
      }

      if (x.none() || k==0)
        return true;

      while (!x[0])
        x >>= 1;

      while (x.count()>1) {
        x >>= 1;

        int count = 0;
        while (!x[0]) {
          x >>= 1;
          ++count;
        }

        if (count < k)
          return false;
      }

      return true;
    }
};


int main() {
  {
    UFUNC(Solution::kLengthApart);
  }
  {
    UFUNC(Solution::kLengthApartBit);
  }
  return 0;
}