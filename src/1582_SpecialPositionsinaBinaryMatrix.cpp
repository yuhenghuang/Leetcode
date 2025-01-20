#include <local_leetcode.hpp>

class Solution {
  public:
    int numSpecial(vector<vector<int>>& mat) {
      const int m = mat.size();
      const int n = mat[0].size();

      vector<int> rowOnes(m), colOnes(n);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (mat[i][j]) {
            ++rowOnes[i];
            ++colOnes[j];
          }

      int res = 0;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (mat[i][j] and rowOnes[i] == 1 and colOnes[j] == 1)
            ++res;

      return res;
    }
};


int main() {
  EXECS(Solution::numSpecial);
  return 0;
}