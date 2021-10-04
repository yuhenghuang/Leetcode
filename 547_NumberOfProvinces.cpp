#include <numeric>
#include <unordered_set>
#include "utils3.hpp"


class UnionFind {
  private:
    vector<int> parent, rank;
  
  public:
    UnionFind(int n): parent(n), rank(n) {
      iota(parent.begin(), parent.end(), 0);
    }

    int find(int p) {
      if (parent[p] == p)
        return p;
      
      return parent[p] = find(parent[p]);
    }

    void add(int p, int q) {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();

      UnionFind uf(n);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) 
          if (isConnected[i][j])
            uf.add(i, j);

      int res = 0;
      unordered_set<int> s;
      for (int i = 0; i < n; ++i) {
        int p = uf.find(i);

        if (s.count(p) == 0) {
          s.insert(p);
          ++res;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::findCircleNum);
  return 0;
}