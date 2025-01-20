#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int i = 0, j = (int) numbers.size() - 1;

      while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum < target)
          ++i;
        else if (sum > target)
          --j;
        else
          return {i+1, j+1};
      }

      return {};
    }
};


int main() {
  EXECS(Solution::twoSum);
  return 0;
}