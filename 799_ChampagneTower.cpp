#include "utils.hpp"

class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
      vector<vector<double>> tower(query_row+1, vector<double>(query_glass+1, 0.0));
      tower[0][0] = poured;

      double temp;
      for (int i=0; i<query_row; ++i)
        for (int j=max(0, i+query_glass-query_row); j<=min(i, query_glass); ++j) {
          if (tower[i][j]>1) {
            temp = 0.5 * (tower[i][j]-1.0);
            if (j>i+query_glass-query_row)
              tower[i+1][j] += temp;
            if (j<query_glass)
              tower[i+1][j+1] += temp;
          }
        }
      
      return min(tower[query_row][query_glass], 1.0);
    }
};

int main() {
  UFUNC(Solution::champagneTower);
  return 0;
}