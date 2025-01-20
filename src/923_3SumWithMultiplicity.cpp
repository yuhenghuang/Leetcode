#include "utils2.hpp"

class Solution {
  public:
    int threeSumMulti(vector<int>& arr, int target) {
      vector<int> freq(101);
      
      for (int num : arr)
        ++freq[num];
      
      constexpr int mod = 1e9 + 7;
      
      int res = 0;
      for (int i=0; i<101; ++i) {
        if (freq[i]==0) continue;
        long x = freq[i]--;
        for (int j=i; j<101; ++j) {
          if (freq[j]==0) continue;
          long y = freq[j]--;

          int k = target - i - j;
          
          if (k < 101 && k >= j) {
            long z = freq[k];
            if (i == j && j == k)
              res = (res + (x * y * z / 6)) % mod;
            else if (i == j || j == k)
              res = (res + (x * y * z / 2)) % mod;
            else
              res = (res + x * y * z) % mod;
          }
          freq[j]++;
        }
        freq[i]++;
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::threeSumMulti);
  return 0;
}