#include "utils3.hpp"

class Solution {
  public:
    int minStartValue(vector<int>& nums) {
      int res = 0;
      int sum = 0;
      for (int num : nums) {
        sum += num;

        if (sum < res)
          res = sum;
      }

      return -res + 1;
    }
};


int main() {
  UFUNCS(Solution::minStartValue);
  return 0;
}