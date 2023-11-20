#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      sort(arr.begin(), arr.end());

      int res = 0;
      for (int num : arr)
        res = min(res + 1, num);

      return res;
    }
};


int main() {
  EXECS(Solution::maximumElementAfterDecrementingAndRearranging);
  return 0;
}