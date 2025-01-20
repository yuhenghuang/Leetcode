#include <local_leetcode.hpp>

class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    UnionFind(int n): parent(n, -1), rank(n) { }

    int find(int p) {
      if (parent[p] < 0)
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
  public:
    long long countPairs(int n, vector<vector<int>>& edges) {
      UnionFind uf(n);

      for (auto& e : edges)
        uf.join(e[0], e[1]);

      // parent id -> count of nodes in subgraph
      vector<int> counts(n);
      for (int i = 0; i < n; ++i)
        ++counts[uf.find(i)];

      int64_t res = 0;

      for (int c : counts)
        if (c > 0)
          res += static_cast<int64_t>(n - c) * c;

      return res >> 1;
    }
};


int main() {
  EXECS(Solution::countPairs);
  return 0;
}