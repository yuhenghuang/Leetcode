#include "utils.hpp"

class Solution {
  public:
    int kthFactor(int n, int k) {
      for (int i=1; i<=n; ++i) 
        if (n % i == 0 && --k==0)
          return i;

      return -1;
    }
};


int main() {
  UFUNC(Solution::kthFactor);
  return 0;
}