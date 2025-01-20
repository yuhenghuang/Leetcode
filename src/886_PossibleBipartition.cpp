#include <local_leetcode.hpp>

class Solution {
  private:
    class UnionFind {
      private:
        vector<int> parent, rank;

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
              parent[q] = p;
              ++rank[p]; 
            }
          }
        }
    };

  public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      vector<vector<int>> graph(n);
      for (auto& e : dislikes) {
        graph[e[0] - 1].push_back(e[1] - 1);
        graph[e[1] - 1].push_back(e[0] - 1);
      }

      UnionFind uf(n);

      for (auto& vertex : graph)
        for (int i = 1; i < vertex.size(); ++i)
          uf.join(vertex[i-1], vertex[i]);

      for (auto& e : dislikes)
        if (uf.find(e[0]-1) == uf.find(e[1]-1))
          return false;

      return true;
    }
};


int main() {
  EXECS(Solution::possibleBipartition);
  return 0;
}