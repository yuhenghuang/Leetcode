#include <local_leetcode.hpp>

class Solution {
  public:
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(), satisfaction.end(), greater<>());

      int res = 0;
      int prefix = 0;
      for (int i = 0; i < (int) satisfaction.size(); ++i) {
        prefix += satisfaction[i];
        if (prefix > 0) [[ likely ]]
          res += prefix;
        else
          break;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxSatisfaction);
  return 0;
}