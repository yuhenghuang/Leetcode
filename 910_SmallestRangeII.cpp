#include "utils.hpp"
#include <algorithm>

class Solution {
  public:
    int smallestRangeII(vector<int>& A, int K) {
      int n = A.size();
      sort(A.begin(), A.end());

      int res = A.back() - A.front();
      for (int i=0; i<n-1; ++i) {
        int high = max(A.back()-K, A[i]+K);
        int low = min(A.front()+K, A[i+1]-K);
        res = min(res, high-low);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::smallestRangeII);
  return 0;
}