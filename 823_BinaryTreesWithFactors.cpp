#include "utils2.hpp"

class Solution {
  public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      
      int n = arr.size();
      
      unordered_map<int, int> num2idx;
      for (int i=0; i<n; ++i)
        num2idx[arr[i]] = i;
      
      constexpr long mod = 1e9 + 7;
      vector<long> dp(n, 1);

      long res = 0;
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
  UFUNC(Solution::numFactoredBinaryTrees);
  return 0;
}