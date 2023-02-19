#include <local_leetcode.hpp>

class Solution {
  public:
    string addBinary(string a, string b) {
      string c; // outcome of a + b
      int rem = 0; // remainder

      // loop from rightmost digit of a and b
      for (int m = (int) a.size() - 1, n = (int) b.size() - 1; m >= 0 || n >= 0 || rem > 0; --m, --n) {
        rem += (m >= 0 ? (a[m] - '0') : 0) + (n >= 0 ? (b[n] - '0') : 0);

        c.push_back((char) ((rem % 2)) + '0');
        rem /= 2;
      }

      reverse(c.begin(), c.end());
      return c;
    }
};


int main() {
  EXECS(Solution::addBinary);
  return 0;
}