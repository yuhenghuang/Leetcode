#include <local_leetcode.hpp>

class Solution {
  public:
    string getSmallestString(int n, int k) {
      string res(n, 'a');
      int v = n;

      int i = n-1;
      while (v < k) {
        if (k-v>25) {
          res[i] = 'z';
          v += 25;
        }
        else {
          res[i] = (k-v) + 'a';
          break;
        }
        --i;
      }

      return res;
    }

    string getSmallestStringNew(int n, int k) {
      string res(n, 'a');

      int val = n;

      for (int i = n - 1; val < k; val += 25, --i) {
        if (k - val > 25)
          res[i] = 'z';
        else
          res[i] +=  k - val;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getSmallestString);
  EXECS(Solution::getSmallestStringNew);
  return 0;
}