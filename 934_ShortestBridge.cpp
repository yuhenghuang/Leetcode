/*
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
*/

#include <local_leetcode.hpp>


class Solution {
  private:
    int m, n;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<pair<int, int>> q;
  public:
    int shortestBridge(vector<vector<int>>& A) {
      m = A.size();
      n = A[0].size();

      // update values of $island 1$ to 2
      bool flag=false;
      for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j)
          if (A[i][j]==1) {
            dfs(i, j, A);
            flag = true;
            break;
          }
        if (flag) break;
      }

      int res=0;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto p = q.front(); q.pop();
          for (int k=0; k<4; ++k) {
            int i = p.first+dir[k][0], j = p.second+dir[k][1];
            if (i<0 || i>=m || j<0 || j>=n || A[i][j]==2) continue;
            // until $island 2$ whose value is 1 is found
            if (A[i][j]==1) return res;

            // expand island 1 by one step each time
            A[i][j] = 2;
            q.push({i, j});
          }
        }
        ++res;
      }
      return -1;
    }

    void dfs(int i, int j, vector<vector<int>>& A) {
      if (i<0 || i>=m || j<0 || j>=n || A[i][j]!=1) return;

      q.push({i, j});
      ++A[i][j];
      for (int k=0; k<4; ++k)
        dfs(i+dir[k][0], j+dir[k][1], A);
    }
};

int main() {
  /*
  Solution sol;
  vector<vector<int>> A = {{0,1,0},{0,0,0},{0,0,1}};
  cout << sol.shortestBridge(A) << endl;
  */

  EXECS(Solution::shortestBridge);
  return 0;
}