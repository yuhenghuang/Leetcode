#include <vector>
using namespace std;

class Solution {
  private:
    int res;
    vector<vector<int>> map;
  public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      map = vector<vector<int>>(n);
      for (auto& edge : edges) {
        map[edge[0]].push_back(edge[1]);
        map[edge[1]].push_back(edge[0]);
      }

      res = 0;
      dfs(-1, 0, hasApple);
      return res;
    }
    bool dfs(int prev, int cur, vector<bool>& hasApple) {
      bool flag = false;
      for (int& next : map[cur]) 
        if (next!=prev && dfs(cur, next, hasApple)) {
          flag = true;
          res += 2;
        }
      return flag | hasApple[cur];
    }
};