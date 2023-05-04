#include <local_leetcode.hpp>

class UnionFind {
  private:
    int df; // degree of freedom

    vector<int> parent;
    vector<int> rank;

  public:
    UnionFind(int n): df(n - 1), parent(n, -1), rank(n) { }

    int find(int p) {
      if (parent[p] == -1)
        return p;
      return parent[p] = find(parent[p]);
    }

    bool join(int p, int q) {
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

        --df;

        return false;
      }

      return true;
    }

    bool connected() const { return df == 0; }
};

class Solution {
  private:
    int connect(int type, vector<vector<int>>& edges, UnionFind& uf) {
      int res = 0;

      for (auto& e : edges)
        if (e[0] == type && uf.join(e[1] - 1, e[2] - 1))
          ++res;

      return res;
    }


  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      UnionFind uf(n);

      int res = connect(3, edges, uf);

      // copy graph after type 3 edges are connected
      UnionFind uf2(uf);

      res += connect(1, edges, uf);
      if (!uf.connected())
        return -1;

      res += connect(2, edges, uf2);
      if (!uf2.connected())
        return -1;

      return res;
    }
};


int main() {
  EXECS(Solution::maxNumEdgesToRemove);
  return 0;
}