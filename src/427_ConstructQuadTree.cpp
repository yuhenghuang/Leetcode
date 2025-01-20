#define QUAD_NODE
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  private:
    Node* recursion(vector<vector<int>>& grid, int r, int c, int k) {
      bool isleaf = true;
      int val = grid[r][c];
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j)
          if (grid[r+i][c+j] != val) {
            isleaf = false;
            break;
          }

        if (!isleaf)
          break;
      }

      if (isleaf)
        return new Node(val, true);
      else {
        k >>= 1;
        return new Node(
          1, false,
          recursion(grid, r, c, k),
          recursion(grid, r, c + k, k),
          recursion(grid, r + k, c, k),
          recursion(grid, r + k, c + k, k)
        );
      }
    }

  public:
    Node* construct(vector<vector<int>>& grid) {
      return recursion(grid, 0, 0, grid.size());
    }
};


int main() {
  EXECS(Solution::construct);
  return 0;
}