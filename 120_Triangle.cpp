#include "utils2.hpp"

class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      for (int i = n-2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
          triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

      return triangle[0][0];
    }
};


int main() {
  UFUNC(Solution::minimumTotal);
  return 0;
}