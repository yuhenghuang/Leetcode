#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
      // O(nlogp + mlogp)
      // m = numLaps
      // n = size of tires
      // p = changeTime + min(f)

      vector<int> time;

      /*
      int temp = INT_MAX;
      for (auto& tire : tires)
        temp = min(tire.front(), temp);

      time.push_back(temp);
      */

      // use reduce to compute the first element of time (e.g. min time to run first lap)
      time.push_back(
        reduce(
          tires.begin(),
          tires.end(),
          INT_MAX,
          [](const int& x, const vector<int>& y) -> const int& { return min(x, y.front()); }
        )
      );

      // min time cost to change tire and move 1 lap
      int minTime = changeTime + time.front();

      for (auto& tire : tires) {
        int f = tire.front();
        int r = tire.back();

        int curr = r;
        // last move must be non-greater than minTime
        // use division to avoid overflow
        for (int i = 1; minTime / curr >= f; ++i) {
          curr *= r;

          if (i == time.size())
            time.push_back(f * (curr - 1) / (r - 1));
          else
            time[i] = min(time[i], f * (curr - 1) / (r - 1));
        }
      }

      vector<int> dp(numLaps + 1, INT_MAX);
      dp[0] = -changeTime;

      for (int i = 0; i < numLaps; ++i)
        for (int j = 0; j < time.size() && i + j < numLaps; ++j) 
          dp[i + j + 1] = min(dp[i + j + 1], dp[i] + changeTime + time[j]);

      return dp.back();
    }
};


int main() {
  EXECS(Solution::minimumFinishTime);
  return 0;
}