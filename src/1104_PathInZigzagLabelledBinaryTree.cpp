#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> pathInZigZagTree(int label) {
      int h = numeric_limits<int>::digits - __builtin_clz(label);

      vector<int> res(h + 1);

      if (h & 1)
        label = (1 << (h + 1)) - 1 - label + (1 << h);

      for (; h >= 0; --h, label >>= 1) 
        res[h] = (h & 1) ? ((1 << (h + 1)) - 1 - label + (1 << h)): label;

      return res;
    }
};


int main() {
  EXECS(Solution::pathInZigZagTree);
  return 0;
}