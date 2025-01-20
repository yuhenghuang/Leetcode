#include <local_leetcode.hpp>

class Solution {
  public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      
      int n = arr.size();
      
      unordered_map<int, int> num2idx;
      for (int i=0; i<n; ++i)
        num2idx[arr[i]] = i;
      
      constexpr int64_t mod = 1e9 + 7;

      // index, num. of binary trees with arr[index] as root
      vector<int64_t> dp(n, 1);

      int64_t res = 0;
      for (int i=0; i<n; ++i) {
        for (int j=0; arr[j] <= arr[i] / arr[j]; ++j)
          if (arr[i] % arr[j] == 0 && num2idx.count(arr[i] / arr[j]) > 0) {
            int k = num2idx[arr[i] / arr[j]];
            
            dp[i] = (dp[i] + dp[j] * dp[k] * (j==k ? 1 : 2)) % mod;
          }

        res = (res + dp[i]) % mod;
      }
        
      return res;
    }
};


int main() {
  EXECS(Solution::numFactoredBinaryTrees);
  return 0;
}
