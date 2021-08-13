#include <numeric>
#include <set>
#include "utils3.hpp"

struct UnionFind {
  vector<int> parent;

  UnionFind(int n): parent(n) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int p) {
    if (parent[p] == p)
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

      set<int> res;
      for (int i = 0; i < n; ++i)
        res.insert(uf.find(i));

      return vector<int>(res.begin(), res.end());
    }
};


int main() {
  UFUNCS(Solution::findSmallestSetOfVertices);
  return 0;
}