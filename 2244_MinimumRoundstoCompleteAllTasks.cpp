#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumRounds(vector<int>& tasks) {
      // task, count
      unordered_map<int, int> m;

      for (auto& t : tasks)
        ++m[t];

      int res = 0;
      for (auto& [t, c] : m) {
        if (c == 1)
          return -1;
        else
          res += c / 3 + (c % 3 ? 1 : 0);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumRounds);
  return 0;
}