#include "utils2.hpp"

class Solution {
  public:
    int minSwap(vector<int>& A, vector<int>& B) {
      int n = A.size();

      int org = 0, swp = 1;

      for (int i=1; i<n; ++i) {
        bool flag = A[i] > A[i-1] && B[i] > B[i-1];
        if (flag && A[i] > B[i-1] && B[i] > A[i-1])
          swp = org = min(org, swp);
        else if (!flag)
          swap(org, swp);
        ++swp;
      }

      return min(org, swp);
    }
};


int main() {
  UFUNC(Solution::minSwap);
  return 0;
}