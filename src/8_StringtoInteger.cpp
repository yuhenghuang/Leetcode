#include <local_leetcode.hpp>

class Solution {
  public:
    int myAtoi(string s) {
      int n = s.size();

      int i = 0;

      // trim leading spaces
      for (; i < n && s[i] == ' '; ++i);

      // identify sign
      bool sign = true;
      if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-')
          sign = false;

        ++i;
      }

      // trim leading zeros
      for (; i < n && s[i] == '0'; ++i);

      // collect remaining digits
      string num;
      for (; i < n && isdigit(s[i]); ++i)
        num.push_back(s[i]);

      if (num.empty())
        return 0;
      else if (num.size() > 10)
        return sign ? INT_MAX : INT_MIN;
      else {
        long temp = stol(num);
        return sign ? min((1L << 31) - 1, temp) : max(-(1L << 31), -temp);
      }
    }
};


int main() {
  EXECS(Solution::myAtoi);
  return 0;
}