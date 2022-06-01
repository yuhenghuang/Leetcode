#include <local_leetcode.hpp>

class Solution {
  public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      vector<int> indegrees(n);
      for (auto& road : roads) {
        ++indegrees[road[0]];
        ++indegrees[road[1]];
      }

      // sort cities by importance (num. of edges)
      vector<int> cities(n);
      iota(cities.begin(), cities.end(), 0);

      sort(
        cities.begin(),
        cities.end(),
        [&indegrees](const int& i, const int& j) -> bool {
          return indegrees[i] < indegrees[j];
        }
      );

      // city -> value
      vector<int> values(n);

      for (int i = 0; i < n; ++i)
        values[cities[i]] = i + 1;

      long long res = 0;

      for (auto& road : roads)
        res += values[road[0]] + values[road[1]];

      return res;
    }
};


int main() {
  EXECS(Solution::maximumImportance);
  return 0;
}