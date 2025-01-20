#include <local_leetcode.hpp>

class Solution {
  public:
    int stoneGameVIII(vector<int>& stones) {
      int n = stones.size();

      int prefix[n];

      prefix[0] = stones[0];
      for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i-1] + stones[i];

      int res = prefix[n-1];
      
      for (int i = n - 2; i > 0; --i) 
        res = max(res, prefix[i] - res);

      return res;
    }
};


int main() {
  EXECS(Solution::stoneGameVIII);
  return 0;
}