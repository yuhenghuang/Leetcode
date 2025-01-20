#include <local_leetcode.hpp>

class Solution {
  public:
    int findJudge(int n, vector<vector<int>>& trust) {
      int count[n+1];
      memset(count, 0, sizeof(count));

      for (auto& t : trust) {
        count[t[0]] = INT_MIN;
        ++count[t[1]];
      }

      int res = -1;
      for (int i = 1; i <= n; ++i)
        if (count[i] == n-1) {
          if (res == -1) // first judge found
            res = i;
          else // second judge found
            return -1;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::findJudge);
  return 0;
}