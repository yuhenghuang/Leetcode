#include <local_leetcode.hpp>

// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n, IsBadVersion isBadVersion) {
      int l=1, r=n;
      while (l<r) {
        int m = (r-l)/2 + l;
        if (isBadVersion(m))
          r = m;
        else
          l = m+1;
      }
      return l;
    }
};


int main() {
  EXECS(Solution::firstBadVersion);
  return 0;
}