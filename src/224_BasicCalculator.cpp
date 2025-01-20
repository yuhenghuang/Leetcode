#include <local_leetcode.hpp>

class Solution {
  private:
    inline 
    int calculate(int x, int y, char op) {
        switch (op) {
          case 'd':
            return y;
          case '+':
            return x + y;
          case '-':
            return x - y;
          default:
            abort();
        }
    }

    int calculate(const string& s, size_t& i) {
      int res = 0;
      int num = 0;
      char op = 'd';

      while (i < s.size() && s[i] != ')') {
        if (s[i] == ' ') {
          // do nothing
        }
        else if (isdigit(s[i]))
          num = num * 10 + (s[i] - '0');
        else { [[ unlikely ]]
          // calculate before next operator or parenthesis
          res = calculate(res, num, op);

          // reset num after calculation
          num = 0;

          if (s[i] == '(') {
            ++i;
            num = calculate(s, i);
          }
          else
            op = s[i];
        }

        ++i;
      }

      // after the scanning
      res = calculate(res, num, op);

      return res;
    }


  public:
    int calculate(string s) {
      size_t i = 0;
      return calculate(s, i);
    }
};


int main() {
  EXECS(Solution::calculate, int, (string));
  return 0;
}