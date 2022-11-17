#include <local_leetcode.hpp>

class Solution {
  public:
    int maximum69Number(int num) {
      stack<int> s;

      int m = 1;
      while (num > 0) {
        m *= 10;

        s.push(num % 10);
        num /= 10;
      }

      int res = 0;
      while (!s.empty()) {
        m /= 10;
        if (s.top() == 6) {
          res += m * 9;
          s.pop();
          break;
        }
        else {
          res += m * 9;
          s.pop();
        }
      }

      while (!s.empty()) {
        m /= 10;
        res += m * s.top();
        s.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximum69Number);
  return 0;
}