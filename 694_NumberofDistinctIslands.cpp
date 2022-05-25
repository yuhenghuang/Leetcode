#include <local_leetcode.hpp>

class UnionFind {
  private:
    vector<int> parent;

  public:
    UnionFind(int n): parent(n, -1) { }

    // find parent
    int find(int p) {
      if (parent[p] == -1)
        return p;
      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        // parent is always left-up corner
        if (p < q)
          parent[q] = p;
        else
          parent[p] = q;
      }
    }
};


// left-up corner cell as (0, 0)
class Island {
  private:
    vector<pair<int, int>> coordinates;

  public:
    Island() = default;

    // move ctor to aoivd unnecessary copies
    Island(Island&& rhs) noexcept : 
      coordinates(std::move(rhs.coordinates)) 
    { }

    // push cell
    void push(int x, int y) { coordinates.emplace_back(x, y); }

    // empty island (no island) ?
    bool empty() const { return coordinates.empty(); }

    struct hash {
      size_t operator()(const Island& island) const {
        size_t val = 0;

        for (auto& [x, y] : island.coordinates) {
          val += ::hash<int>()(x);
          val = (val * 3) + ::hash<int>()(y);
        }

        return val;
      }
    };

    // compare coordinates of cells from up-left -> bottom-right in a row-major manner
    bool operator==(const Island& rhs) const {
      // use built-in comparison of vector and pair
      return coordinates == rhs.coordinates;
    }
};


class Solution {
  private:
    static constexpr int dirs[2][2] = {{0,1}, {1,0}};

  public:
    int numDistinctIslands(vector<vector<int>>& grid) {
      int m = grid.size(); // num. of rows
      int n = grid[0].size(); // num. of columns

      UnionFind uf(m * n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1)
            for (auto& d : dirs) {
              int r = i + d[0];
              int c = j + d[1];

              if (r < m && c < n && grid[r][c] == 1) 
                uf.join(i * n + j, r * n + c);
            }

      // hast set of islands
      unordered_set<Island, Island::hash> s;

      vector<Island> islands(m * n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          if (grid[i][j] == 1) {
            int p = uf.find(i * n + j);
            islands[p].push(i - p / n, j - p % n);
          }

      for (Island& i : islands)
        if (!i.empty())
          s.insert(std::move(i));

      return s.size();
    }
};


int main() {
  EXECS(Solution::numDistinctIslands);
  return 0;
}