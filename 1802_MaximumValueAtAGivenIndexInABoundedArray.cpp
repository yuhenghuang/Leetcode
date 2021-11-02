#include "utils3.hpp"

class Solution {
  private:
    long area(long d, long h) {
      return (h + max(h - d, 0L) + 1) * min(d, h) / 2 + max(d - h, 0L);
    }

  public:
    int maxValue(int n, int index, int maxSum) {
      int l = 1, r = maxSum;
      while (l < r) {
        int m = l + (r - l) / 2 + (r - l) % 2;
        
        if (area(index + 1, m) + area(n - index, m) - m > maxSum)
          r = m - 1;
        else
          l = m;
      }

      return l;
    }
};


int main() {
  UFUNCS(Solution::maxValue);
  return 0;
}