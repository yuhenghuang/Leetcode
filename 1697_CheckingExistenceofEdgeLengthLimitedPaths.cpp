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
          parent[q] = p;
          ++rank[p];
        }
      }
    }
};


class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
      typedef tuple<int, int, int> iii_t;

      // d, u, v
      vector<iii_t> edges(edgeList.size());

      for (auto& e : edgeList)
        edges.emplace_back(e[2], e[0], e[1]);

      sort(
        edges.begin(), edges.end(),
        [](const iii_t& p, const iii_t& q) { return get<0>(p) < get<0>(q); }
      );

      int m = queries.size();
      vector<bool> res(m);

      vector<int> indices(m);
      iota(indices.begin(), indices.end(), 0);

      sort(
        indices.begin(), indices.end(),
        [&queries] (int i, int j) { return queries[i][2] < queries[j][2]; }
      );

      UnionFind uf(n);

      int j = 0;
      for (int i : indices) {
        for (; j < (int) edges.size() && get<0>(edges[j]) < queries[i][2]; ++j)
          uf.join(get<1>(edges[j]), get<2>(edges[j]));

        if (uf.find(queries[i][0]) == uf.find(queries[i][1]))
          res[i] = true;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::distanceLimitedPathsExist);
  return 0;
}