#include "utils3.hpp"

class Solution {
  private:
    int fall(int i, int j, int n, vector<vector<int>>& grid) {
      if (i == grid.size())
        return j;

      // column of neighbor index needed to check the direction of board
      int k = j + grid[i][j];
      if (k < 0 || k == n || grid[i][k] != grid[i][j])
        return -1;

      return fall(i + 1, k, n, grid);
    }

  public:
    vector<int> findBall(vector<vector<int>>& grid) {
      int n = grid[0].size();

      vector<int> res;
      for (int j = 0; j < n; ++j)
        res.push_back(fall(0, j, n, grid));

      return res;
    }
};


int main() {
  UFUNCS(Solution::findBall);
  return 0;
}