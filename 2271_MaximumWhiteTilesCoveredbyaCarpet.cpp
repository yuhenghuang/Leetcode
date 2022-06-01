#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    int lower_bound(vector<ii_t>& arr, int t, int l, int r) {
      while (l < r) {
        int m = l + (r - l) / 2;

        if (arr[m].first < t)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }

  public:
    int maximumWhiteTiles(vector<vector<int>>& _tiles, int carpetLen) {
      int n = _tiles.size();

      // start index, length
      vector<ii_t> tiles;
      tiles.reserve(n);

      for (auto& t : _tiles)
        tiles.emplace_back(t[0], t[1] - t[0] + 1);

      sort(tiles.begin(), tiles.end());

      // can be optimized out...
      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + tiles[i].second;

      int res = 0;
      for (int i = 0; i < n; ++i) {
        int t = tiles[i].first + carpetLen;

        // can be further optimized to nest with outer loop since j is increasing
        int j = lower_bound(tiles, t, i, n) - 1;

        res = max(res, prefix[j] - prefix[i] + min(t - tiles[j].first, tiles[j].second));

        // early stop
        if (j + 1 == n)
          break;
      }

      return res;
    }

    int maximumWhiteTilesO1(vector<vector<int>>& _tiles, int carpetLen) {
      // O(1) memory

      int n = _tiles.size();
      vector<ii_t> tiles(n);

      for (int i = 0; i < n; ++i) {
        tiles[i].first = _tiles[i][0];
        tiles[i].second = _tiles[i][1];
      }

      sort(tiles.begin(), tiles.end());

      int res = 0;

      int j = 0;
      int covered = 0;
      for (int i = 0; i < n; ++i) {
        auto& [s, e] = tiles[i];

        // cover [s, t)
        int t = s + carpetLen;

        while (j < n && tiles[j].second < t) {
          covered += tiles[j].second - tiles[j].first + 1;
          ++j;
        }

        if (j == n) {
          res = max(res, covered);
          break;
        }
        else
          res = max(res, covered + max(0, t - tiles[j].first));

        covered -= e - s + 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumWhiteTiles);
  EXECS(Solution::maximumWhiteTilesO1);
  return 0;
}