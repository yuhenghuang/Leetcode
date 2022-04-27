#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
      typedef pair<int, int> pii_t;

      int n = scores.size();

      vector<vector<pii_t>> graph(n);

      for (auto& e : edges) {
        graph[e[0]].emplace_back(scores[e[1]], e[1]);
        graph[e[1]].emplace_back(scores[e[0]], e[0]);
      }

      for (auto& neighbors : graph)
        sort(neighbors.begin(), neighbors.end(), greater<>());

      int res = -1;

      for (auto& e : edges) {
        int i = 0;
        for (auto& [p, u] : graph[e[0]]) {
          if (++i > 3)
            break;

          if (u == e[1])
            continue;

          int j = 0;
          for (auto& [q, v] : graph[e[1]]) {
            if (++j > 3)
              break;

            if (v != e[0] && v != u)
              res = max(res, p + q + scores[e[0]] + scores[e[1]]);
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumScore);
  return 0;
}