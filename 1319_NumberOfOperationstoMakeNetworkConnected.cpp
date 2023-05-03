#include <local_leetcode.hpp>

class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    UnionFind(int n): parent(n, -1), rank(n) { }

    int find(int p) {
      if (parent[p] == -1)
        return p;
      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        if (rank[p] > rank[q])
          parent[q] = p;
        else if (rank[p] < rank[q])
          parent[p] = q;
        else {
          ++rank[p];
          parent[q] = p;
        }
      }
    }
};

class Solution {
  private:
    vector<bool> visited;
    vector<vector<int>> graph;
  public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      int res = -1;
      if (connections.size()<n-1) return res;

      graph = vector<vector<int>>(n);
      for (auto& edge : connections) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      visited = vector<bool>(n, false);
      for (int i=0; i<n; ++i)
        if (!visited[i]) {
          ++res;
          dfs(-1, i);
        }
      return res;
    }

    void dfs(int prev, int cur) {
      visited[cur] = true;
      for(int next : graph[cur])
        if (next != prev && !visited[next])
          dfs(cur, next);
    }

    int makeConnectedUF(int n, vector<vector<int>>& connections) {
      if (connections.size() < n - 1)
        return -1;

      UnionFind uf(n);

      for (auto& con : connections)
        uf.join(con[0], con[1]);

      vector<bool> is_parent(n);
      for (int i = 0; i < n; ++i)
        is_parent[uf.find(i)] = true;

      return count(is_parent.begin(), is_parent.end(), true) - 1;
    }
};


int main() {
  EXECS(Solution::makeConnected);
  EXECS(Solution::makeConnectedUF);
  return 0;
}