#include <local_leetcode.hpp>

class Solution {
  private:
    function<int (int)> guess;

  public:
    int guessNumber(int n) {
      int l = 1, r = n;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (guess(m) > 0)
          l = m + 1;
        else if (guess(m) < 0)
          r = m - 1;
        else
          return m;
      }

      return -1;
    }

    int guessNumber(int n, int pick) {
      guess = [pick](int num) { return num > pick ? -1 : (num < pick ? 1 : 0); };

      return guessNumber(n);
    }

    int guessNumber(int n, Guess guess) {
      int l = 1, r = n;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (guess(m) > 0)
          l = m + 1;
        else if (guess(m) < 0)
          r = m - 1;
        else
          return m;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::guessNumber, int, (int, int));
  EXECS(Solution::guessNumber, int, (int, Guess));
  return 0;
}