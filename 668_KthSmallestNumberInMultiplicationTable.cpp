#include "utils3.hpp"

class Solution {
  public:
    int findKthNumber(int m, int n, int k) {
      if (m > n)
        swap(m , n);

      int l = 1, r = m * n;
      while (l < r) {
        int mid = l + (r - l) / 2;

        int count = 0;
        for (int i = 1; i <= min(m, mid); ++i)
          count += min(n, mid / i);

        if (count < k)
          l = mid + 1;
        else
          r = mid;
      }

      return l;
    }
};


int main() {
  UFUNCS(Solution::findKthNumber);
  return 0;
}