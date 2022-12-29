#include <local_leetcode.hpp>

class Solution {
  public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

      // indicies from 0 to n - 1
      vector<int> indicies(profit.size());

      iota(indicies.begin(), indicies.end(), 0);
      sort(indicies.begin(), indicies.end(),
        [&endTime](int i, int j) -> bool {
          return endTime[i] < endTime[j];
        }
      );

      map<int, int, greater<int>> m;
      m[0] = 0;
      for (int i : indicies) {
        // max of do or not do the job
        m[endTime[i]] = max(m.begin()->second, profit[i] + m.lower_bound(startTime[i])->second);
      }

      return m.begin()->second;
    }
};


int main() {
  EXECS(Solution::jobScheduling);
  return 0;
}