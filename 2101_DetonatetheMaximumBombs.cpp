#include <local_leetcode.hpp>

class Solution {
  private:
    class UnionFind {
      private:
        vector<int> parent;

      public:
        UnionFind(int n): parent(n, -1) { }

        int find(int p) {
          if (parent[p] < 0)
            return p;
          
          return parent[p] = find(parent[p]);
        }

        void unite(int p, int q) {
          p = find(p);
          q = find(q);

          if (p != q)
            parent[p] = q;
        }
    };

    int64_t square(int64_t x) { return x*x;}

    int dfs(int v, const vector<vector<int>>& graph, bool visited[]) {
      if (visited[v])
        return 0;

      visited[v] = true;

      int res = 1;
      for (int w : graph[v])
        res += dfs(w, graph, visited);

      return res;
    }

  public:
    int maximumDetonationWrong(vector<vector<int>>& bombs) {
      // the edge is not undirected

      int n = bombs.size();

      UnionFind uf(n);
      for (int i = 1; i < n; ++i) {
        vector<int>& x = bombs[i];
        for (int j = 0; j < i; ++j) {
          vector<int>& y = bombs[j];

          if (square(x[0] - y[0]) + square(x[1] - y[1]) < square(x[2] + y[2]))
            uf.unite(i, j);
        }
      }

      vector<int> count(n);

      for (int i = 0; i < n; ++i)
        ++count[uf.find(i)];

      return *max_element(count.begin(), count.end());
    }


    int maximumDetonation(vector<vector<int>>& bombs) {
      int n = bombs.size();

      vector<vector<int>> graph(n);
      for (int i = 1; i < n; ++i) {
        vector<int>& x = bombs[i];
        for (int j = 0; j < i; ++j) {
          vector<int>& y = bombs[j];

          int64_t dist = square(x[0] - y[0]) + square(x[1] - y[1]);

          if (dist <= square(x[2])) 
            graph[i].push_back(j);

          if (dist <= square(y[2])) 
            graph[j].push_back(i);
        }
      }

      bool visited[n];

      int res = 0;
      for (int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof(visited));
        res = max(res, dfs(i, graph, visited));
      }
        
      return res;
    }
};


int main() {
  EXECS(Solution::maximumDetonation);
  return 0;
}