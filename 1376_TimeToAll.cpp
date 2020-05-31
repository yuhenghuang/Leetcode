#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<int>> graph;
    int res;
  public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      graph = vector<vector<int>>(n);
      for (int i=0; i<n; ++i)
        if (i!=headID)
          graph[manager[i]].push_back(i);

      res = 0;
      dfs(headID, 0, informTime);
      return res;
    }

    void dfs(int v, int t, vector<int>& informTime) {
      if (graph[v].size()==0) {
        res = max(res, t);
        return;
      }

      for (int& w : graph[v]) 
        dfs(w, t+informTime[v], informTime);
    }
};