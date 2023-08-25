#include <local_leetcode.hpp>

class Solution {
  public:
    int longestSubsequence(vector<int>& arr, int difference) {
      unordered_map<int, int> m;

      int res = 0;
      for (int num : arr)
        res = max(m[num] = m[num - difference] + 1, res);

      return res;
    }
};


int main() {
  EXECS(Solution::longestSubsequence);
  return 0;
}