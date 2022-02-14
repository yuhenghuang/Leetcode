#include <local_leetcode.hpp>

class Solution {
  public:
    int countOperations(int num1, int num2) {
      int i = 0;
      for (;num1 > 0 and num2 > 0; ++i) {
        if (num1 > num2)
          num1 -= num2;
        else
          num2 -= num1;
      }

      return i;
    }
};


int main() {
  EXECS(Solution::countOperations);
  return 0;
}