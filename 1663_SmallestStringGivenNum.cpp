#include "utils2.hpp"

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
};


int main() {
  UFUNC(Solution::getSmallestString);
  return 0;
}