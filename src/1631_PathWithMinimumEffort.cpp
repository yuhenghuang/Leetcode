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

    bool join(int p, int q) {
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

        return true;
      }

      return false;
    }
};

class Solution {
  private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  public:
    int minimumEffortPath(const vector<vector<int>>& heights) {
      const int m = heights.size(), n = m==0 ? 0 : heights[0].size();

      bool seen[m][n];
      memset(seen, 0, m*n);

      static const int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
      const int target = m*n-1;

      priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>> heap;

      heap.emplace(0, 0);
      while (!heap.empty()) {
        auto p = heap.top(); heap.pop();
        int idx = p.second;
        if (idx==target)
          return p.first;

        int p_i = idx / n, p_j = idx % n;
        if (seen[p_i][p_j])
          continue;
        
        seen[p_i][p_j] = true;
        for (int k=0; k<4; ++k) {
          int i = p_i + dir[k][0];
          int j = p_j + dir[k][1];
          if (i<0 || i>=m || j<0 || j>=n || seen[i][j])
            continue;

          heap.emplace(
            max(p.first, abs(heights[i][j] - heights[p_i][p_j])),
            i*n+j
          );
        }
      }

      return 0;
    }

    int minimumEffortPathUF(const vector<vector<int>>& heights) {
      typedef tuple<int, int, int> iii_t;

      const int m = heights.size();
      const int n = heights[0].size();

      if (m * n == 1)
        return 0;

      // weight, u, v
      priority_queue<iii_t, vector<iii_t>, greater<iii_t>> heap;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int u = i * n + j;
          for (int k = 0; k < 2; ++k) {
            int r = i + dirs[k][0];
            int c = j + dirs[k][1];
            if (r >= 0 && r < m && c >= 0 && c < n)
              heap.emplace(
                abs(heights[i][j] - heights[r][c]),
                u,
                r * n + c
              );
          }
        }

      UnionFind uf(m * n);
      while (true) {
        auto& [w, u, v] = heap.top();

        if (uf.join(u, v) && uf.find(0) == uf.find(m*n - 1))
          return w;

        heap.pop();
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::minimumEffortPath);
  EXECS(Solution::minimumEffortPathUF);
  return 0;
}