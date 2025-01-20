#include "utils2.hpp"

class Solution {
  public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      int n = A.size();
      vector<int> idx(n);
      for (int i=0; i<n; ++i)
        idx[i] = i;
      
      sort(A.begin(), A.end());
      
      sort(
        idx.begin(), idx.end(),
        [&B](int x, int y) -> bool {
          return B[x] < B[y];
        }
      );
      
      int j = 0;
      int k = n-1;
      vector<int> res(n);
      for (int i=0; i<n; ++i) {
        if (A[i] > B[idx[j]])
          res[idx[j++]] = A[i];
        else
          res[idx[k--]] = A[i];
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::advantageCount);
  return 0;
}