#include "utils2.hpp"

class Solution {
  public:
    int numberOfArithmeticSlices(vector<int>& A) {
      int n = A.size();

      int res = 0;
      int i = 0;
      while (i+2 < n) {
        int d = A[i+1] - A[i];
        int j = i+1;
        while (j+1 < n && A[j+1]-A[j] == d)
          ++j;

        if (j-i > 1)
          res += (j-i-1) * (j-i) / 2;

        i = j;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::numberOfArithmeticSlices);
  return 0;
}