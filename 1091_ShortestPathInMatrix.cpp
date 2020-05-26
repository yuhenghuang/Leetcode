#include <vector>
#include <queue>
using namespace std;

class Solution {
  private:
    int dir[8][2] = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1},
      {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };
  public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int m = grid.size(), n = m==0 ? 0 : grid[0].size();
      if (n==0 || grid[0][0]) return -1;
      // else if (m==1 && n==1) return 1;
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<pair<int, int>> q;

      q.push({-1, -1});
      // visited[0][0] = true;
      int res=1;
      while (!q.empty()) {
        int N = q.size()+1;
        while (--N) {
          int cur_i = q.front().first, cur_j = q.front().second;
          q.pop();
          for (auto& move : dir) {
            int i = cur_i + move[0], j = cur_j + move[1];
            if (i<0 || i>=m || j<0 || j>=n || grid[i][j] || visited[i][j]) continue;
            if (i==m-1 && j==n-1) return res;
            visited[i][j] = true;
            q.push({i, j});
          }
        }
        ++res;
      }

      return -1;
    }
};