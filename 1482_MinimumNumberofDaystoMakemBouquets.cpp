#include <local_leetcode.hpp>

class Solution {
  public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      if ((int)bloomDay.size() / m < k)
        return -1;

      int l = 1, r = 1e9;
      while (l <= r) {
        int mid = l + (r - l) / 2;

        int bouquet = 0;
        int count = 0;
        for (const int& days : bloomDay)
          if (days <= mid) {
            if (++count == k) {
              ++bouquet;
              count = 0;
            }
          }
          else
            count = 0;
            
        if (bouquet < m)
          l = mid + 1;
        else
          r = mid - 1;
      }

      return l;
    }
};


int main() {
  EXECS(Solution::minDays);
  return 0;
}