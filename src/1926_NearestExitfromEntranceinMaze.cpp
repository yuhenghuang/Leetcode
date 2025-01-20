#include <local_leetcode.hpp>

class Solution {
  public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      int m = maze.size();
      int n = maze[0].size();

      bool seen[m][n];
      memset(seen, 0, sizeof(seen));
      seen[entrance[0]][entrance[1]] = true;

      queue<pair<int, int>> q;
      q.emplace(entrance[0],  entrance[1]);

      int res = 1;
      int dirs[4][2] {{0,1}, {1,0}, {0,-1}, {-1,0}};

      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto [ii, jj] = q.front();

          for (auto& d : dirs) {
            int i = ii + d[0];
            int j = jj + d[1];

            if (0 <= i && i < m && 0 <= j && j < n && maze[i][j] == '.' && !seen[i][j]) {
              if (0 == i || i == m-1 || 0 == j || j == n-1)
                return res;

              seen[i][j] = true;
              q.emplace(i, j);
            }
          }

          q.pop();
        }

        ++res;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::nearestExit);
  return 0;
}