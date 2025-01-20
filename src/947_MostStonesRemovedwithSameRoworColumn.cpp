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
        if (rank[p] < rank[q])
          parent[p] = q;
        else if (rank[p] > rank[q])
          parent[q] = p;
        else {
          parent[q] = p;
          ++rank[p];
        }
      }
    }
};


class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {
      // location on x or y axis
      // for bucket sort
      int axis[10001];

      int n = stones.size();

      UnionFind uf(n);

      memset(axis, -1, sizeof(axis));
      for (int i = 0; i < n; ++i) {
        int x = stones[i][0];

        if (axis[x] >= 0)
          uf.join(i, axis[x]);
        else
          axis[x] = i;
      }

      memset(axis, -1, sizeof(axis));
      for (int i = 0; i < n; ++i) {
        int y = stones[i][1];

        if (axis[y] >= 0)
          uf.join(i, axis[y]);
        else
          axis[y] = i;
      }

      // index, is parent?
      vector<bool> parent(n);
      for (int i = 0; i < n; ++i)
        parent[uf.find(i)] = true;

      int res = n;
      for (auto b : parent)
        if (b)
          --res;

      return res;
    }
};


int main() {
  EXECS(Solution::removeStones);
  return 0;
}