#include "utils3.hpp"

class Solution {
  public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
      vector<int> indegree(n);
      vector<vector<int>> graph(n);

      for (auto& r : relations) {
        ++indegree[r[1]-1];
        graph[r[0]-1].push_back(r[1]-1);
      }

      queue<int> q;
      for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
          q.push(i);


      vector<int> months(n);
      while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int w : graph[v]) {
          months[w] = max(months[w], months[v] + time[v]);

          if (--indegree[w] == 0)
            q.push(w);
        }
      }

      int res = 0;
      for (int i = 0; i < n; ++i)
        res = max(res, months[i] + time[i]);

      return res;
    }
};


int main() {
  UFUNCS(Solution::minimumTime);
  return 0;
}