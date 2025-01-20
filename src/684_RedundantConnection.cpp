#include "utils2.hpp"

class UnionFind {
  private:
    vector<int> parent, rank;

  public:
    UnionFind(int n): parent(n), rank(n) {
      for (int i = 1; i < n; ++i)
        parent[i] = i;
    }

    int find(int p) {
      if (parent[p] == p)
        return p;
        
      return parent[p] = find(parent[p]);
    }

    bool join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p == q)
        return false;
      else {
        if (rank[p] > rank[q])
          parent[q] = p;
        else if (rank[q] < rank[p])
          parent[p] = q;
        else {
          parent[q] = p;
          ++rank[p];
        }

        return true;
      }
    }
};

class Solution {
  public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      // circle detection
      UnionFind uf(edges.size()+1);
      for (vector<int>& e : edges) 
        if (!uf.join(e[0], e[1]))
          return e;

      return {};
    }
};


int main() {
  UFUNC(Solution::findRedundantConnection);
  return 0;
}