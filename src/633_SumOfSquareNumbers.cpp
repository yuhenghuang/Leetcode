#include <cmath>
#include "utils3.hpp"

constexpr size_t N = 46340;

class Solution {
  private:
    static int candidates[N];

  public:
    static int helper() {
      for (int i = 0; i < N; ++i)
        candidates[i] = i * i;

      return 0;
    }

    bool judgeSquareSum(int c) {
      int* i = candidates;
      int* j = i + N - 1;
      
      // find best upper bound j by binary search
      j = lower_bound(i, j, c);

      // two pointer nested loop
      while (i <= j) {
        int b = c - *i;
        if (b > *j)
          ++i;
        else if (b < *j)
          --j;
        else
          return true;
      }

      return false;
    }
};

int Solution::candidates[N];
static const int emm = Solution::helper();

int main() {
  UFUNCS(Solution::judgeSquareSum);
  return 0;
}