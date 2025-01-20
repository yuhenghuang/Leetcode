#include <local_leetcode.hpp>

class Solution {
  public:
    int minMoves(int target, int maxDoubles) {
      int res = 0;
      
      // 0 -> target = res + target
      while (target > 0 && maxDoubles > 0) {
        if (target & 1) 
          target -= 1;
        else {
          --maxDoubles;
          target >>= 1;
        }

        ++res;
      }

      // 1 -> target = (0 -> target) - 1
      return res + target - 1;
    }
};


int main() {
  EXECS(Solution::minMoves);
  return 0;
}