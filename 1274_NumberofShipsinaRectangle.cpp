#include <local_leetcode.hpp>

class Solution {
  private:
    int countShipsImpl(Sea& sea, int x1, int y1, int x2, int y2) {
      if (!sea.hasShips({x2, y2}, {x1, y1}))
        return 0;

      if (x1 == x2 && y1 == y2)
        return 1;
      else if (x1 == x2) {
        int ym = y1 + (y2 - y1) / 2;
        return countShipsImpl(sea, x1, y1, x2, ym) + countShipsImpl(sea, x1, ym+1, x2, y2);
      }
      else if (y1 == y2) {
        int xm = x1 + (x2 - x1) / 2;
        return countShipsImpl(sea, x1, y1, xm, y2) + countShipsImpl(sea, xm+1, y1, x2, y2);
      }
      else {
        int xm = x1 + (x2 - x1) / 2;
        int ym = y1 + (y2 - y1) / 2;

        return 
          countShipsImpl(sea, x1, y1, xm, ym) + 
          countShipsImpl(sea, xm + 1, y1, x2, ym) +
          countShipsImpl(sea, x1, ym + 1, xm, y2) +
          countShipsImpl(sea, xm + 1, ym + 1, x2, y2);
      }
    }

  public:
    int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft) {
      return countShipsImpl(sea, bottomLeft[0], bottomLeft[1], topRight[0], topRight[1]);
    }

};


int main() {
  EXECS(Solution::countShips);
  return 0;
}