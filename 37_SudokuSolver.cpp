#include "utils3.hpp"

class Solution {
  private:
    bool dfs(int idx, 
             array<array<bool, 9>, 9>& row, 
             array<array<bool, 9>, 9>& col,
             array<array<bool, 9>, 9>& box,
             vector<vector<char>>& board) {
      if (idx == 81)
        return true;

      int i = idx / 9;
      int j = idx % 9;
      int k;
      if (board[i][j] == '.') {
        for (k = 0; k < 9; ++k) 
          if (!(row[i][k] || col[j][k] || box[i/3 * 3 + j/3][k])) {
            row[i][k] = true;
            col[j][k] = true;
            box[i/3 * 3 + j/3][k] = true;

            if (dfs(idx + 1, row, col, box, board)) {
              board[i][j] = '1' + k;
              return true;
            }

            row[i][k] = false;
            col[j][k] = false;
            box[i/3 * 3 + j/3][k] = false;
          }
        return false;
      }
      else 
        return dfs(idx + 1, row, col, box, board); 
    }

  public:
    void solveSudoku(vector<vector<char>>& board) {
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
            
            row[i][k] = true;
            col[j][k] = true;
            box[i/3 * 3 + j/3][k] = true;
          }

      dfs(0, row, col, box, board);
    }
};


int main() {
  UFUNCS(Solution::solveSudoku);
  return 0;
}