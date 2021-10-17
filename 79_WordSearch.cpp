#include "utils3.hpp"

static const vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
  private:
    int m, n;
    bool flag;

    void dfs(const char* w, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
      if (*w == '\0') {
        flag = true;
        return;
      }
      else if (flag || i < 0 || i == m || j < 0 || j == n || visited[i][j] || board[i][j] != *w)
        return;


      ++w;
      visited[i][j] = true;

      for (auto& d : dirs) 
        dfs(w, i + d[0], j + d[1], board, visited);

      visited[i][j] = false;
    }

  public:
    bool exist(vector<vector<char>>& board, string word) {
      m = board.size();
      n = board.empty() ? 0 : board.front().size();
      flag = false;

      vector<vector<bool>> visited(m, vector<bool>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          dfs(word.c_str(), i, j, board, visited);

      return flag;
    }
};


int main() {
  UFUNCS(Solution::exist);
  return 0;
}