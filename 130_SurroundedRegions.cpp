#include <vector>
#include <queue>
using namespace std;

class Solution {
  private:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool> > seen;
  public:
    void solve(vector< vector<char> >& board) {
      m = board.size();
      n = m==0 ? 0 : board[0].size();

      queue<pair<int, int> > q;
      for (int i=0; i<m; ++i) {
        q.push(make_pair(i, -1));
        q.push(make_pair(i, n));
      }

      for (int j=1; j<n-1; ++j) {
        q.push(make_pair(-1, j));
        q.push(make_pair(m, j));
      }

      while (!q.empty()) {
        auto p = q.front();
        q.pop();
      }

      seen = vector<vector<bool> >(m, vector<bool>(n, false));
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (!seen[i][j] && board[i][j]=='O')
    }

    // bool dfs(int i, int j, vector< vector<char> >& board) {
    //   if (i<0 || i>=m || j<0 || j>=n) return true;
    //   if (board[i][j]=='X') return false;

    //   seen[i][j] = true;
    //   board[i][j] = 'X';

    //   bool flag = false;
    //   for (int k=0; k<4; ++k) {
    //     flag |= dfs(i+dir[k][0], j+dir[k][1], board);
    //     if (flag)
    //       break;
    //   }

    //   if (flag)
    //     board[i][j] = 'O';
    //   return flag;
    // }
};