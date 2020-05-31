#include <vector>
#include <queue>
#include <iostream>
using namespace std;

static int emm = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 1;
}();

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> inDegree(numCourses, 0);
      vector<vector<int>> graph(numCourses);
      for (auto& edge : prerequisites) {
        graph[edge[0]].push_back(edge[1]);
        ++inDegree[edge[1]];
      }

      queue<int> q;
      for (int i=0; i<numCourses; ++i)
        if (inDegree[i]==0)
          q.push(i);

      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int& w : graph[v]) {
          --inDegree[w];
          if (inDegree[w]==0)
            q.push(w);
        }
      }

      for (int& d : inDegree)
        if (d!=0)
          return false;
      return true;
    }
};