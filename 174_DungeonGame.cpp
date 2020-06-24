#include <vector>
#include <iostream>
using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m=dungeon.size(), n= m==0? 0 : dungeon[0].size();
      if (n==0) return 0;

      vector<vector<int>> dp(m, vector<int>(n, 0));
      dp[m-1][n-1] = max(0, -dungeon[m-1][n-1]);
      for (int i=m-2; i>=0; --i)
        dp[i][n-1] = max(0, dp[i+1][n-1] - dungeon[i][n-1]);

      for (int j=n-2; j>=0; --j)
        dp[m-1][j] = max(0, dp[m-1][j+1] - dungeon[m-1][j]);

      for (int i=m-2; i>=0; --i)
        for (int j=n-2; j>=0; --j)
          dp[i][j] = max(0, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
      return dp[0][0]+1;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
  cout << sol.calculateMinimumHP(dungeon) << endl;
  return 0;
}