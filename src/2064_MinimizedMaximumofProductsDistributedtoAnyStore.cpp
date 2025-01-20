#include "utils3.hpp"

class Solution {
  public:
    int minimizedMaximum(int n, vector<int>& quantities) {
      int l = 1, r = 1e5;

      while (l < r) {
        int m = l + (r - l) / 2;

        int temp = 0;
        for (int i = 0; i < quantities.size(); ++i)
          temp += quantities[i] / m + (quantities[i] % m ? 1 : 0);

        if (temp <= n)
          r = m;
        else
          l = m + 1;
      }

      return r;
    }
};


int main() {
  UFUNCS(Solution::minimizedMaximum);
  return 0;
}