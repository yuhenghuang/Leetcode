#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      // (color, ball count)
      unordered_map<int, int> m;

      // ball, color
      unordered_map<int, int> balls;

      int count = 0;

      vector<int> res;
      res.reserve(queries.size());
      for (const auto& q : queries) {
        int x = q[0];
        int y = q[1];
        int& z = balls[x];
        // color of ball x (i.e. z) changes
        if (z != y) {
          if (z > 0 and --m[z] == 0)
            --count;

          if (m[y]++ == 0)
            ++count;

          z = y;
        }

        res.push_back(count);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::queryResults);
  return 0;
}