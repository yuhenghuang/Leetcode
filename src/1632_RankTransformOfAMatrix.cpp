#include <numeric>
#include "utils3.hpp"

class UnionFind {
  private:
    vector<int> parent;

  public:
    UnionFind(int n): parent(n) {
      iota(parent.begin(), parent.end(), 0);
    }

    int find(int p) {
      if (p == parent[p])
        return p;

      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);
      if (p != q)
        parent[q] = p;
    }
};

class Solution {
  private:
    typedef pair<int, int> pii;

  public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();

      vector<pii> coordinates;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          coordinates.emplace_back(matrix[i][j], i*n + j);

      sort(coordinates.begin(), coordinates.end());

      UnionFind uf(m * n);

      unordered_map<int, int> num2idx;
      for (int i = 0; i < m; ++i) {
        num2idx.clear();
        for (int j = 0; j < n; ++j) {
          int num = matrix[i][j];

          auto iter = num2idx.find(num);
          if (iter != num2idx.end())
            uf.join(i*n + j, i * n + iter->second);

          num2idx[num] = j;
        }
      }

      for (int j = 0; j < n; ++j) {
        num2idx.clear();
        for (int i = 0; i < m; ++i) {
          int num = matrix[i][j];

          auto iter = num2idx.find(num);
          if (iter != num2idx.end())
            uf.join(i*n + j, (iter->second) * n + j);

          num2idx[num] = i;
        }
      }

      vector<int> rows_rank(m), rows_max(m, INT_MIN);
      vector<int> cols_rank(n), cols_max(n, INT_MIN);

      vector<int> ranks(m * n);
      for (int i = 0; i < m * n; ++i) {
        int r = coordinates[i].second / n;
        int c = coordinates[i].second % n;
        int num = coordinates[i].first;

        if (num > rows_max[r]) {
          ++rows_rank[r];
          rows_max[r] = num;
        }

        if (num > cols_max[c]) {
          ++cols_rank[c];
          cols_max[c] = num;
        }

        // parent index
        int p = uf.find(r*n + c);

        ranks[p] = max(ranks[p], max(rows_rank[r], cols_rank[c]));

        if (i < m * n - 1 && coordinates[i+1].first != num) {
          for (int j = i; j >= 0 && coordinates[j].first == num; --j) {
            pii& pj = coordinates[j];
            rows_rank[pj.second / n] = cols_rank[pj.second % n] = ranks[uf.find(pj.second)];
          }
        }
      }

      vector<vector<int>> res(m, vector<int>(n));
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          res[i][j] = ranks[uf.find(i*n + j)];

      return res;
    }


    vector<vector<int>> matrixRankTransformTreeMap(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();

      map<int, vector<pair<int,int>>> coordinates;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          coordinates[matrix[i][j]].push_back({i, j});


      UnionFind uf(m * n);

      unordered_map<int, int> num2idx;
      for (int i = 0; i < m; ++i) {
        num2idx.clear();
        for (int j = 0; j < n; ++j) {
          int num = matrix[i][j];

          auto iter = num2idx.find(num);
          if (iter != num2idx.end())
            uf.join(i*n + j, i * n + iter->second);

          num2idx[num] = j;
        }
      }

      for (int j = 0; j < n; ++j) {
        num2idx.clear();
        for (int i = 0; i < m; ++i) {
          int num = matrix[i][j];

          auto iter = num2idx.find(num);
          if (iter != num2idx.end())
            uf.join(i*n + j, (iter->second) * n + j);

          num2idx[num] = i;
        }
      }

      vector<int> rows_rank(m), rows_max(m, INT_MIN);
      vector<int> cols_rank(n), cols_max(n, INT_MIN);

      vector<int> ranks(m * n);
      vector<vector<int>> res(m, vector<int>(n));
      for (auto& coord : coordinates) {
        for (auto& p : coord.second) {
          int r = p.first;
          int c = p.second;
          if (coord.first > rows_max[r]) {
            ++rows_rank[r];
            rows_max[r] = coord.first;
          }

          if (coord.first > cols_max[c]) {
            ++cols_rank[c];
            cols_max[c] = coord.first;
          }

          // parent index
          int parent = uf.find(r*n + c);

          ranks[parent] = max(ranks[parent], max(rows_rank[r], cols_rank[c]));
        }

        for (auto& p : coord.second) {
          int r = p.first;
          int c = p.second;

          res[r][c] = rows_rank[r] = cols_rank[c] = ranks[uf.find(r*n + c)];
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::matrixRankTransform);
  UFUNCS(Solution::matrixRankTransformTreeMap);
  return 0;
}