#include <local_leetcode.hpp>

class Solution {
  public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();

      vector<vector<int>> prefix(m+1, vector<int>(n+1));
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          prefix[i+1][j+1] =  prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] + matrix[i][j];

      int res = 0;

      unordered_map<int, int> count;
      for (int r1=0; r1<m; ++r1)
        for (int r2=r1; r2<m; ++r2) {
          count.clear();
          count[0] = 1;
          for (int c=0; c<n; ++c) {
            int sum = prefix[r2+1][c+1] - prefix[r1][c+1];
            res += count[sum - target];
            ++count[sum];
          }
        }

      return res;
    }
};


int main() {
  EXECS(Solution::numSubmatrixSumTarget);
  return 0;
}
