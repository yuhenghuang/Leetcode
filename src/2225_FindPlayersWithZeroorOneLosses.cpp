#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      vector<vector<int>> res(2);

      // player, # of losses
      map<int, int> m;

      for (auto& match : matches) {
        m[match[0]]; // initialize m[player] as 0 or do nothing
        ++m[match[1]];
      }

      for (auto& [player, loss] : m)
        if (loss < 2)
          res[loss].push_back(player);

      return res;
    }
};


int main() {
  EXECS(Solution::findWinners);
  return 0;
}