#include <local_leetcode.hpp>

class Solution {
  private:
    bool found;

    int16_t airportId(const string& airport) {
      int16_t id = 0;

      for (int i = 0; i < 3; ++i)
        id = (id * 26) + (airport[i] - 'A');

      return id;
    }

    void dfs(int16_t u, vector<int>& res, unordered_map<int, bool>& seen, unordered_map<int16_t, vector<int16_t>>& graph) {
      seen[u] = true;
      res.push_back(u);

      for (int16_t v : graph[u])
        if (!seen[v])
          dfs(v, res, seen, graph);

      if (res.size() == seen.size())
        found = true;

      if (found)
        return;

      seen[u] = false;
      res.pop_back();
    }

  public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      // incomplete answer...
      // need adding count to tickets

      found = false;

      // from, tos
      unordered_map<int16_t, vector<int16_t>> graph;

      for (auto& t : tickets)
        graph[airportId(t[0])].push_back(airportId(t[1]));

      unordered_map<int, bool> seen;
      for (auto& [from, tos] : graph) {
        sort(tos.begin(), tos.end());
        seen[from] = false;
        for (int id : tos)
          seen[id] = false;
      }

      vector<int> res;
      dfs(airportId("JFK"), res, seen, graph);

      vector<string> itinerary;

      transform(
        res.begin(), res.end(),
        back_inserter(itinerary),
        [] (int16_t id) -> string {
          string airport = "***";

          for (int i = 2; i >= 0; --i) {
            airport[i] = 'A' + (id % 26);
            id /= 26;
          }

          return airport;
        }
      );

      return itinerary;
    }
};


int main() {
  EXECS(Solution::findItinerary);
  return 0;
}