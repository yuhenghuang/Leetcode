#include "utils2.hpp"

class Solution {
  public:
    int scoreOfParentheses(string S) {
      stack<int> s;
      for (char c : S) {
        if (c == '(')
          s.push(0);
        else {
          if (s.top() == 0)
            s.top() = 1;
          else {
            int temp = 0;
            while (s.top() != 0) {
              temp += s.top();
              s.pop();
            }

            s.top() = temp * 2;
          }
        }
      }

      int res = 0;
      while (!s.empty()) {
        res += s.top();
        s.pop();
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::scoreOfParentheses);
  return 0;
}