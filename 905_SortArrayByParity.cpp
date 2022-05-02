#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> sortArrayByParity(vector<int>& A) {
      // sort(A.begin(), A.end(), [](const int &a, const int &b){ return (a%2==0) && (b%2==1); });

      size_t l = 0, r = A.size()-1;
      while (l < r) {
        if (A[l] % 2 == 1) {
          if (A[r] % 2 == 0)
            swap(A[l], A[r]);
          else --r;
        }
        else
          ++l;
      }
      return A;
    }
};


int main() {
  EXECS(Solution::sortArrayByParity);
  return 0;
}