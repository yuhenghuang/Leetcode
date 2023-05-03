#include <local_leetcode.hpp>

class Solution {
  public:
    int addDigits(int num) {
      while (num>9) {
        int next = 0;
        while (num) {
          next += num % 10;
          num /= 10;
        }
        num = next;
      }
      return num;
    }
};


int main() {
  EXECS(Solution::addDigits);
  return 0;
}
