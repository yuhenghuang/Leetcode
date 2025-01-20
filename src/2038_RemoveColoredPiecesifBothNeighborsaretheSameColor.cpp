#include <local_leetcode.hpp>

class Solution {
  public:
    bool winnerOfGame(string colors) {
      int moveable[2] = {0};

      int consecutive = 1;
      for (int i = 1; i < static_cast<int>(colors.size()); ++i) {
        if (colors[i-1] == colors[i])
          ++consecutive;
        else
          consecutive = 1;

        if (consecutive > 2)
          ++moveable[colors[i] - 'A'];
      }

      return moveable[0] > moveable[1];
    }
};


int main() {
  EXECS(Solution::winnerOfGame);
  return 0;
}