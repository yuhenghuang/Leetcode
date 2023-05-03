#include <local_leetcode.hpp>

class Solution {
  private:
    enum class COLOR {
      WHITE,
      GREY,
      BLACK
    };

  public:
    int longestCycle(vector<int>& edges) {
      int n = edges.size();

      vector<COLOR> colors(n, COLOR::WHITE);
      vector<int> depths(n);

      function<int (int, int)> dfs = [&edges, &colors, &depths, &dfs](int u, int d) -> int {
        colors[u] = COLOR::GREY; // in search
        depths[u] = d;

        int v = edges[u];

        int res = -1;
        if (v >= 0) {
          if (colors[v] == COLOR::WHITE)
            res = dfs(v, d + 1);
          else if (colors[v] == COLOR::GREY)
            res = d - depths[v] + 1;
        }

        colors[u] = COLOR::BLACK; // searched
        return res;
      };


      int res = -1;
      for (int i = 0; i < n; ++i)
        res = max(res, dfs(i, 0));

      return res;
    }
};


int main() {
  EXECS(Solution::longestCycle);
  return 0;
}