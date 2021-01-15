#include "utils.hpp"

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      // if (n==0) return;
      for (int i=m-1; i>=0; --i)
        nums1[i+n] = nums1[i];

      int i=0, j=0, idx=0;
      while (idx<m+n) {
        int n1 = i<m ? nums1[n + i] : INT_MAX;
        int n2 = j<n ? nums2[j] : INT_MAX;

        if (n1 < n2) {
          ++i;
          nums1[idx++] = n1;
        }
        else {
          ++j;
          nums1[idx++] = n2;
        }
      }
    }
};


int main() {
  UFUNC(Solution::merge);
  return 0;
}