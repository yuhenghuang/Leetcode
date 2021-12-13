#include <unordered_set>
#include "utils3.hpp"

class Solution {
  private:
    void dfs(int v, const int s, const unordered_map<int, int>& graph, vector<vector<int>>& res) {
      if (v != s) {
        auto iter = graph.find(v);
        if (iter != graph.end()) {
          res.push_back({v, iter->second});
          dfs(iter->second, s, graph, res);
        }
      }
    }

  public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
      typedef pair<int, int> ii_t;

      // 
      vector<int> edge_in, edge_out;

      // node, (outdegree, indegree)

      unordered_map<int, int> graph;
      unordered_map<int, pair<int, int>> count;
      for (auto& p : pairs) {
        if (++count[p[0]].first > 1)
          edge_out = p;
        else
          graph[p[0]] = p[1];

        if (++count[p[1]].second > 1)
          edge_in = p;
      }

      vector<vector<int>> res;

      // start in a circle and stretch out
      if (!edge_out.empty()) {

        // act as if edge_out is the first edge (and not saved in graph)
        res.push_back(edge_out);
        dfs(edge_out[1], -1, graph, res);

        // now we know if edge_out is not the first edge
        if (res.size() < pairs.size()) {
          res.clear();
          int start = graph[edge_out[0]];

          res.push_back({edge_out[0], start});

          graph[edge_out[0]] = edge_out[1];
          dfs(start, -1, graph, res);
        }
      }
      // one circle
      else if (edge_in.empty() && count.size() == pairs.size()) {
        vector<int>& pair = pairs.front();

        res.push_back(pair);
        dfs(pair[1], pair[0], graph, res);
      }
      // from outside of a circle or non-circle
      else {
        int start;
        for (auto& p : count)
          if (p.second.second == 0) {
            start = p.first;
            break;
          }
        
        // entrypoint of circle if a circle exists
        int end = edge_in.empty() ? -1 : edge_in[1];

        dfs(start, end, graph, res);

        // add edges inside the circle
        if (!edge_in.empty()) {
          start = graph[end];
          res.push_back({end, start});
          dfs(start, end, graph, res);
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::validArrangement);
  return 0;
}