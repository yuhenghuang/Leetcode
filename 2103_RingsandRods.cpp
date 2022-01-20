#include <local_leetcode.hpp>

class Solution {
  public:
    int countPoints(string rings) {
      int nods[10] = {0};
      unordered_map<char, int> m{{'R', 1}, {'G', 2}, {'B', 4}};

      for (int i = 0; i < rings.size(); i += 2) 
        nods[rings[i+1] - '0'] |= m[rings[i]];

      int res = 0;
      for (int i = 0; i < 10; ++i)
        if (nods[i] == 7)
          ++res;

      return res;
    }
};


int main() {
  EXECS(Solution::countPoints);
  return 0;
}