#include <local_leetcode.hpp>

class Solution {
  private:
    class UnionFind {
      private:
        vector<int> parent;

      public:
        UnionFind(int _n): parent(_n) {
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
            if (p < q)
              parent[q] = p;
            else
              parent[p] = q;
          }
        }
    };

  public:
    int numSimilarGroups(vector<string>& strs) {
      int n = strs.size();
      int m = strs[0].size();

      int d = 1;
      while (d * d < m)
        ++d;

      d = min(12, d);

      int buckets = m / 2 + (m % d ? 1 : 0);

      size_t encode[n][buckets];
      memset(encode, 0, sizeof(encode));

      for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; j += d)
          for (int k = 0; k < d && j + k < m; ++k) 
            encode[i][j / d] |= (strs[i][j+k] - 'a') << (k * 5);

      
      UnionFind uf(n);

      vector<int> diffs;
      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j) {
          diffs.clear();
          for (int k = 0; k < buckets; ++k)
            if (encode[i][k] != encode[j][k])
              diffs.push_back(k);

          if (diffs.size() > 2)
            break;
          else if (diffs.empty())
            uf.join(i, j);
          else if (diffs.size() == 1) {
            int count = 0; // count of different chars
            for (int l = diffs[0] * d; l < min(m, diffs[0] * d + d); ++l)
              if (strs[i][l] != strs[j][l])
                ++count;

            if (count == 2)
              uf.join(i, j);
          }
          else {
            int count = 0; // count of different chars
            for (int l = diffs[0] * d; l < min(m, diffs[0] * d + d); ++l)
              if (strs[i][l] != strs[j][l])
                ++count;

            for (int l = diffs[1] * d; l < min(m, diffs[1] * d + d); ++l)
              if (strs[i][l] != strs[j][l])
                ++count;

            if (count == 2)
              uf.join(i, j);
          }
        }

      
      unordered_set<int> s;
      for (int i = 0; i < n; ++i)
        s.insert(uf.find(i));

      return s.size();
    }
};


int main() {
  EXECS(Solution::numSimilarGroups);
  return 0;
}