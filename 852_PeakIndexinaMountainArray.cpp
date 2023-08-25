#include <local_leetcode.hpp>

class Solution {
  public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int l = 1, r = arr.size() - 2;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] > arr[m+1])
          r = m - 1;
        else
          l = m + 1;
      }
      
      return l;
    }
};


int main() {
  EXECS(Solution::peakIndexInMountainArray);
  return 0;
}