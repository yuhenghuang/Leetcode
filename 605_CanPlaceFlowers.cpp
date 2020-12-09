#include "utils.hpp"

class Solution {
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int N = flowerbed.size(), l = 0, r = 0;
      while (r<N) {
        while (l<N && flowerbed[l])
          ++l;

        r = l;
        while (r<N && flowerbed[r]==0)
          ++r;

        int len = r - l - (l!=0) - (r!=N);

        n -= (len + 1) / 2;
        if (n<=0)
          return true;

        l = r+1;
      }

      return false;
    }
};


int main() {
  UFUNC(Solution::canPlaceFlowers);
  return 0;
}