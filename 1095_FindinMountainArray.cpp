#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Comp>
    int binary_search(int l, int r, int t, MountainArray& arr) {
      Comp comp;

      while (l <= r) {
        int m = l + (r - l) / 2;
        int num = arr.get(m);

        if (num == t)
          return m;
        else if (comp(num, t))
          l = m + 1;
        else
          r = m - 1;
      }

      return -1;
    }

  public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      const int n = mountainArr.length();

      int l = 1, r = n - 2;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (mountainArr.get(m) > mountainArr.get(m+1))
          r = m - 1;
        else
          l = m + 1;
      }

      int p = l; // peak index

      // search on left side
      int res = binary_search<less<int>>(0, p, target, mountainArr);

      // search on right side if not found
      if (res < 0)
        res = binary_search<greater<int>>(p, n - 1, target, mountainArr);

      return res;
    }
};


int main() {
  EXECS(Solution::findInMountainArray);
  return 0;
}