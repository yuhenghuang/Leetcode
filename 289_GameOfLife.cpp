#include "utils.hpp"

class Solution {
  private:
    int m, n;

    int element(const vector<vector<int>>& board, int i, int j) {
      if (i<0 || i>=m || j<0 || j>=n)
        return 0;
      else
        return 1 & board[i][j];
    }

  public:
    void gameOfLife(vector<vector<int>>& board) {
      m = board.size();
      n = board[0].size();

      int s;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
          s = 0;

          for (int p=-1; p<2; ++p)
            for (int q=-1; q<2; ++q)
              if (p || q)
                s += element(board, i+p, j+q);

          board[i][j] |= s << 1;
        }

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
          board[i][j] = (board[i][j] >> 1)==3 || 
                        ((board[i][j] & 1) && (board[i][j] >> 1)==2);
    }
};


int main() {
  UFUNC(Solution::gameOfLife);
  return 0;
}