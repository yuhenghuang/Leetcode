#include <local_leetcode.hpp>

class Solution {
  public:
    int addRungs(vector<int>& rungs, int dist) {

      int res = 0;
      int height = 0;
      for (const int& rung : rungs) {
        res += (rung - height - 1) / dist;

        height = rung;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::addRungs);
  return 0;
}