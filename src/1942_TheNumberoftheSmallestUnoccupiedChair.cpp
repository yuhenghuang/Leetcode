#include <local_leetcode.hpp>

class Solution {
  public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
      // the arrival time of target friend
      int target = times[targetFriend][0];

      sort(
        times.begin(),
        times.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x.front() < y.front();
        }
      );

      typedef pair<int, int> pii_t;

      priority_queue<int, vector<int>, greater<int>> chairs;

      // leave time, chair
      priority_queue<pii_t, vector<pii_t>, greater<pii_t>> leaves;

      // current last chair
      int uid = 0;
      for (auto& t : times) {
        while (!leaves.empty() && leaves.top().first <= t.front()) {
          chairs.push(leaves.top().second);
          leaves.pop();
        }

        if (t.front() == target)
          return chairs.empty() ? uid : chairs.top();

        if (chairs.empty())
          leaves.emplace(t.back(), uid++);
        else {
          leaves.emplace(t.back(), chairs.top());
          chairs.pop();
        }
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::smallestChair);
  return 0;
}