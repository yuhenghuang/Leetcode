#include <local_leetcode.hpp>

class Solution {
  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

      int cx1 = max(ax1, bx1);
      int cx2 = min(ax2, bx2);
      int cy1 = max(ay1, by1);
      int cy2 = min(ay2, by2);

      int intersect = max(0, cx2 - cx1) * max(0, cy2 - cy1);

      return area - intersect;
    }
};


int main() {
  EXECS(Solution::computeArea);
  return 0;
}