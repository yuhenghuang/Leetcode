#include <vector>
using namespace std;

class Solution {
  private:
    int m, n, oldColor, newColor;
    int row[4] = {1, -1, 0, 0};
    int clm[4] = {0, 0, -1, 1};
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      m = image.size();
      n = m>0 ? image[0].size() : 0;
      oldColor = (m>0 && n>0) ? image[sr][sc] : -1;
      this->newColor = newColor;
      if (oldColor!=newColor)
        dfs(sr, sc, image);
      return image;
    }

    void dfs(int i, int j, vector<vector<int>>& img) {
      if (i<0 || i>=m || j<0 || j>=n || img[i][j]!=oldColor) return;
      img[i][j] = newColor;
      for (int k=0; k<4; ++k)
        dfs(i+row[k], j+clm[k], img);
    }
};