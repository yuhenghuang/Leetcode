#include <local_leetcode.hpp>

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

    bool canPlaceFlowersFor(vector<int>& flowerbed, int n) {
      if (n == 0)
        return true;

      int m = flowerbed.size();
      for (int i = 0; i < m; ++i)
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == m - 1 || flowerbed[i+1] == 0)) {
          ++i;

          if (--n == 0)
            return true;
        }

      return false;
    }
};


int main() {
  EXECS(Solution::canPlaceFlowers);
  EXECS(Solution::canPlaceFlowersFor);
  return 0;
}