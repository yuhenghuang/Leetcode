#include <vector>
using namespace std;

class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int m = grid.size(), n = m==0 ? 0 : grid[0].size();
      int s = 0, b = 0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          if (grid[i][j]) {
            ++s;
            if (j<n-1 && grid[i][j+1])
              ++b;
            if (i<m-1 && grid[i+1][j])
              ++b;
          }
      return (s << 2) - (b << 1);
    }
};