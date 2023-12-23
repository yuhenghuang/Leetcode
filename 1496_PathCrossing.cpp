#include <local_leetcode.hpp>

class Solution {
  public:
    bool isPathCrossing(string path) {
      unordered_set<int> s;
      s.insert((10000 << 16) | 10000);

      int i = 0, j = 0;
      for (char c : path) {
        switch (c) {
          case 'N':
            ++j; break;
          case 'S':
            --j; break;
          case 'E':
            ++i; break;
          case 'W':
            --i; break;
          default:
            abort();
        };

        int val = ((i + 10000) << 16) | (j + 10000);

        if (!s.count(val))
          s.insert(val);
        else
          return true;
      }

      return false;
    }
};


int main() {
  EXECS(Solution::isPathCrossing);
  return 0;
}