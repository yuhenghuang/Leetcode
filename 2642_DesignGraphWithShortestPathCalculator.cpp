#include <local_leetcode.hpp>

class Graph {
  private:
    typedef pair<int, int> ii_t;

    vector<vector<ii_t>> graph;

  public:
    Graph(int n, vector<vector<int>>& edges): graph(n) {
      for (auto& e : edges)
        graph[e[0]].emplace_back(e[1], e[2]);
    }
    
    void addEdge(vector<int> edge) {
      graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
      bool seen[100] = {0};

      priority_queue<ii_t, vector<ii_t>, function<bool (const ii_t&, const ii_t&)>> heap(
        [] (const ii_t& p, const ii_t& q) -> bool { return p.first > q.first; }
      );
      heap.emplace(0, node1);

      while (!heap.empty()) {
        auto [dist, u] = heap.top();
        heap.pop();

        if (u == node2)
          return dist;
        else if (seen[u])
          continue;

        seen[u] = true;
        for (auto [v, d] : graph[u])
          if (!seen[v]) 
            heap.emplace(dist + d, v);
      }

      return -1;
    }
};


int main() {
  EXECX(
    CTOR(int, vector<vector<int>>&),
    &Graph::addEdge,
    &Graph::shortestPath
  );
  return 0;
}