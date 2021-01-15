#include "utils.hpp"

class Solution {
  public:
    int getMaximumGenerated(int n) {
      int arr[n+2];
      arr[0] = 0;
      arr[1] = 1;

      int res=0;
      for (int i=1; i<=n; ++i) {
        arr[i] = i%2==0 ? arr[i/2] : arr[i/2] + arr[i/2 + 1];
        res = max(res, arr[i]);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::getMaximumGenerated);
  return 0;
}