#include <local_leetcode.hpp>

class Solution {
  public:
    int findSpecialInteger(vector<int>& arr) {
      // time complexity: O(8 * logn)

      const int n = arr.size();

      for (int i = 0; i < n; i += (n >> 2)) {
        int target = arr[i];
        int freq = upper_bound(arr.begin() + i + 1, arr.end(), target) - lower_bound(arr.begin(), arr.begin() + i + 1, target);

        if (freq > (n >> 2))
          return target;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::findSpecialInteger);
  return 0;
}