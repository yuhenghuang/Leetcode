#include <local_leetcode.hpp>

struct UnionFind {
  vector<int> parent;

  UnionFind(int n): parent(n, -1) { }

  int find(int p) {
    if (parent[p] == -1)
      return p;
    
    return parent[p] = find(parent[p]);
  }

  void join(int v, int w) {
    parent[w] = find(v);
  }
};


class Solution {
  public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      UnionFind uf(n);

      for (vector<int>& e : edges)
        uf.join(e[0], e[1]);

      vector<int> res;
      for (int i = 0; i < n; ++i)
        if (uf.find(i) == i)
          res.push_back(i);

      return res;
    }
};


int main() {
  EXECS(Solution::findSmallestSetOfVertices);
  return 0;
}