#include "utils.hpp"

class Solution {
  public:
    int longestMountain(vector<int>& A) {
      int n = A.size();
      int l = 0;
      while (l<n-1 && A[l] >= A[l+1])
        ++l;
      int res = 0;
      while (l<n-1) {
        int m = l;
        while (m<n-1 && A[m] < A[m+1])
          ++m;

        int r = m;
        while (r<n-1 && A[r] > A[r+1])
          ++r;

        if (l<m && m<r)
          res = max(res, r-l+1);

        l = r; 
        while (l<n-1 && A[l] == A[l+1])
          ++l;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::longestMountain);
  return 0;
}