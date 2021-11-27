#include "utils3.hpp"

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

    // p and q are already parents in each group
    // p != q
    void join(int p, int q) {
      if (rank[p] < rank[q])
        parent[p] = q;
      else if (rank[p] > rank[q])
        parent[q] = p;
      else {
        parent[q] = p;
        ++rank[p];
      }
    }
};

class Solution {
  public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
      UnionFind uf(n);
      vector<bool> res(requests.size(), true);

      for (int i = 0; i < requests.size(); ++i) {
        int p = uf.find(requests[i][0]);
        int q = uf.find(requests[i][1]);

        if (p != q) {
          bool flag = true;
          for (vector<int>& r : restrictions) {
            r[0] = uf.find(r[0]);
            r[1] = uf.find(r[1]);

            if ((r[0] == p && r[1] == q) || (r[0] == q && r[1] == p)) {
              flag = false;
              break;
            }
          }

          if (flag)
            uf.join(p, q);
          else
            res[i] = false;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::friendRequests);
  return 0;
}