#include <local_leetcode.hpp>

class Solution {
  private:
    // find lower bound index in arr given target
    // if target is duplicate, find the rightmost one
    int binary_search(vector<int>& arr, int l, int r, int t) {
      while (l < r) {
        int m = l + (r - l) / 2;

        if (arr[m] > t)
          r = m;
        else
          l = m + 1;
      }

      // r is the leftmost index larger than target
      return arr[r - 1] < t ? r : r - 1;
    }

  public:
    int fixedPoint(vector<int>& arr) {
      int n = arr.size();

      // conditions of fixed point not satisfied. (common domain)
      if (arr.front() >= n || arr.back() < 0)
        return -1;

      int i = 0;
      while (i < n) {
        if (arr[i] > i)
          i = arr[i];
        else if (arr[i] < i)
          // ++i;
          // better to find the lowerbound in arr non-less than i by binary search
          i = binary_search(arr, i + 1, n, i);
        else
          return i;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::fixedPoint);
  return 0;
}