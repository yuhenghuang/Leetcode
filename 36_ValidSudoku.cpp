#include <local_leetcode.hpp>

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      array<array<bool, 9>, 9> row, col, box;

      for (int i = 0; i < 9; ++i) {
        row[i].fill(false);
        col[i].fill(false);
        box[i].fill(false);
      }

      for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) 
          if (board[i][j] != '.') {
            // 0 ~ 8
            int k = board[i][j] - '1';
            if (row[i][k] || col[j][k] || box[i/3 * 3 + j/3][k])
              return false;
            
            row[i][k] = true;
            col[j][k] = true;
            box[i/3 * 3 + j/3][k] = true;
          }

      return true;
    }
};


int main() {
  EXECS(Solution::isValidSudoku);
  return 0;
}