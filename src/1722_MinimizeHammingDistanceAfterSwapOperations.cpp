#include <numeric>
#include <unordered_set>
#include "utils3.hpp"

class UnionFind {
  private:
    vector<int> rank;
    vector<int> parent;

  public:
    UnionFind(int n): parent(n), rank(n) {
      iota(parent.begin(), parent.end(), 0);
    }

    int find(int p) {
      if (parent[p] == p)
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      int n = target.size();

      UnionFind uf(n);
      for (auto& e :allowedSwaps)
        uf.join(e[0], e[1]);


      vector<unordered_multiset<int>> graph(n);

      for (int i = 0; i < n; ++i)
        graph[uf.find(i)].insert(source[i]);

      int d = 0;
      for (int i = 0; i < n; ++i) {
        unordered_multiset<int>& s = graph[uf.find(i)];

        auto iter = s.find(target[i]);
        if (iter != s.end()) 
          s.erase(iter);
        else
          ++d;
      }

      return d;
    }
};


int main() {
  UFUNCS(Solution::minimumHammingDistance);
  return 0;
}