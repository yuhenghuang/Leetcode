#include "utils3.hpp"

static const int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

class Solution {
  private:
    int m, n;

    bool dfs(int i, int j, vector<vector<bool>>& seen, vector<vector<char>>& board) {
      if (i < 0 || i >= m || j < 0 || j >= n)
        return false;
      else if (board[i][j] == 'X' || seen[i][j])
        return true;

      seen[i][j] = true;

      for (int k = 0; k < 4; ++k)
        if (!dfs(i + dirs[k][0], j + dirs[k][1], seen, board))
          return false;

      board[i][j] = 'X';
      return true;
    }

    void dfs(int i, int j, int p, vector<int>& parent, vector<vector<char>>& board) {
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X' || parent[i * n + j] >= 0)
        return;

      parent[i * n + j] = p;

      for (int k = 0; k < 4; ++k)
        dfs(i + dirs[k][0], j + dirs[k][1], p, parent, board);
    }

    void visit(int i, int j, vector<vector<bool>>& seen, vector<vector<char>>& board) {
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X' || seen[i][j])
        return;

      seen[i][j] = true;

      for (int k = 0; k < 4; ++k)
        dfs(i + dirs[k][0], j + dirs[k][1], seen, board);
    }

  public:
    void solveWrong(vector<vector<char>>& board) {
      // wrong answer

      m = board.size();
      n = m == 0 ? 0 : board[0].size();

      vector<vector<bool>> seen(m, vector<bool>(n));
      
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (board[i][j] == 'O' && !seen[i][j])
            dfs(i, j, seen, board);
    }

    void solve(vector<vector<char>>& board) {
      m = board.size();
      n = m == 0 ? 0 : board[0].size();

      // find regions
      vector<int> parent(m * n, -1);

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          if (board[i][j] == 'O') 
            dfs(i, j, i * n + j, parent, board);

      // check neighbors
      // it would be faster to only check elements on boarders
      // no need to stick on general solutions
      vector<bool> results(m * n, true);
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) 
          if (board[i][j] == 'O') {
            int p = parent[i * n + j];
            // if the region is still valid currently
            if (results[p]) 
              for (int k = 0; k < 4; ++k) {
                int ii = i + dirs[k][0];
                int jj = j + dirs[k][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) {
                  results[p] = false;
                  break;
                }
              }
        }

      
      // make changes to board
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (board[i][j] == 'O' && results[parent[i * n + j]])
            board[i][j] = 'X';
    }


    void solveFaster(vector<vector<char>>& board) {
      m = board.size();
      n = m == 0 ? 0 : board[0].size();

      if (m == 0 || n == 0)
        return;

      vector<vector<bool>> seen(m, vector<bool>(n));

      for (int i = 0; i < m; ++i) {
          visit(i, 0, seen, board);

          if (n > 1)
            visit(i, n - 1, seen, board);
      }

      for (int j = 1; j < n; ++j) {
          visit(0, j, seen, board);

          if (m > 1)
            visit(m - 1, j, seen, board);
      }

      for (int i = 1; i < m - 1; ++i)
        for (int j = 1; j < n - 1; ++j)
          if (board[i][j] == 'O' && !seen[i][j])
            board[i][j] = 'X';
    }
};


int main() {
  UFUNCS(Solution::solve);
  UFUNCS(Solution::solveFaster);
  return 0;
}