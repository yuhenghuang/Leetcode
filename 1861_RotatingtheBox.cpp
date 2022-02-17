#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int m = box.size();
      int n = box[0].size();

      vector<vector<char>> res(n, vector<char>(m, '.'));

      vector<int> bottom(m, n - 1);

      // (i, j) -> anti-clockwise -> (col# - 1 - j, i)
      for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < m; ++j) {
          if (box[m - 1 - j][i] == '#') {
            res[bottom[j]--][j] = '#';
          }
          else if (box[m - 1 - j][i] == '*') {
            bottom[j] = i - 1;
            res[i][j] = '*';
          }
        }

      return res;
    }
};


int main() {
  EXECS(Solution::rotateTheBox);
  return 0;
}