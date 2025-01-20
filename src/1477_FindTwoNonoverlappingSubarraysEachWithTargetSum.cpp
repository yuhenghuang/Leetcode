#include <local_leetcode.hpp>

class Solution {
  public:
    int minSumOfLengths(vector<int>& arr, int target) {
      const int n = arr.size();

      unordered_map<int, int> m; // prefix sum, index

      vector<int> dp(n + 1, INT_MAX);

      int prefix = 0;
      m[0] = -1;

      for (int i = 0; i < n; ++i) {
        prefix += arr[i];

        m[prefix] = i;
      }
    }
};


int main() {
  EXECS(Solution::minSumOfLengths);
  return 0;
}