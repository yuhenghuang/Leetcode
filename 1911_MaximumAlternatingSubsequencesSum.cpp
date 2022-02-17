#include <local_leetcode.hpp>

class Solution {
  public:
    long long maxAlternatingSum(vector<int>& nums) {
      long long odd = 0;
      long long even = 0;

      for (const int& num : nums) {
        long long tmp = even;

        even = max(even, odd - num);
        odd = max(odd, tmp + num);
      }

      return max(odd, even);
    }
};


int main() {
  EXECS(Solution::maxAlternatingSum);
  return 0;
}