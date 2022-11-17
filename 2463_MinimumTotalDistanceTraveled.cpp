#include <local_leetcode.hpp>

class Solution {
  private:
    typedef long long ll_t;

    // first i robots, first j slots -> total distance
    // PS: slots = factory x limit
    static ll_t dp[101][10001];

  public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& _factory) {
      typedef pair<int, int> ii_t;

      // (position, limit) of factory
      // the strength of pair<int, int> over vector<int>
      // 1. light to sort (size : 8UL v.s. 24UL)
      // 2. convenient to unpack elements
      vector<ii_t> factory;
      transform(
        _factory.begin(), _factory.end(), 
        back_inserter(factory), 
        [](const vector<int>& p) -> ii_t { return {p.front(), p.back()}; }
      );

      sort(robot.begin(), robot.end());
      sort(factory.begin(), factory.end());

      int m = robot.size(); // num. of robots

      // num. of slots (factory x limit)
      int n = accumulate(
        factory.begin(), factory.end(), 0,
        [] (const int& x, const ii_t& p) { return x + p.second; }
      );

      for (int i = 0; i < m; ++i) { // robot index
        int j = 0; // slot indexs
        for (auto& [y, s] : factory) {
          int dist = abs(robot[i] - y);
          for (int k = 0; k < s; ++k, ++j)
            // more slots than robots
            if (j > i) [[likely]]
              dp[i+1][j+1] = min(dp[i][j] + dist, dp[i+1][j]);
            // # of robots == # of slots
            else if (j == i) [[unlikely]]
              dp[i+1][j+1] = dp[i][j] + dist;
        }
      }

      return dp[m][n];
    }
};

// default initialization to 0 now at c++17?
Solution::ll_t Solution::dp[101][10001];


int main() {
  EXECS(Solution::minimumTotalDistance);
  return 0;
}