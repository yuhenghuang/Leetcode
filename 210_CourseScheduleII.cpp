#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>
 
enum COLOR {WHITE, GREY, BLACK};

class Solution {
  private:
    vector<COLOR> clr;
    vector<vector<int>> graph;
    vector<int> res;
    bool flag; // circle detected
    int idx;

    void dfs(int v) {
      if (flag) return;

      clr[v] = GREY;
      for (int w : graph[v]) {
        if (clr[w]==WHITE)
          dfs(w);
        else if (clr[w]==GREY)
          flag = true;
      }
      clr[v] = BLACK;
      res[--idx] = v;
    }

  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      graph.assign(numCourses, vector<int>());

      for (auto& pre : prerequisites)
        graph[pre[1]].push_back(pre[0]);

      idx = numCourses;
      flag = false;
      res.resize(numCourses);
      clr.assign(numCourses, WHITE);

      for (int i=0; i<numCourses; ++i)
        if (clr[i] == WHITE)
          dfs(i);

      if (flag)
        return {};
      else 
        return res;
    }

    vector<int> findOrderBFS(int n, vector<vector<int>>& prerequisites) {
      vector<vector<int>> graph(n);

      vector<int> indegree(n);
      for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        ++indegree[p[0]];
      }

      queue<int> q;
      for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
          q.push(i);

      vector<int> res;
      res.reserve(n);
      while (!q.empty()) {
        int& v = q.front();
        res.push_back(v);

        for (int w : graph[v])
          if (--indegree[w] == 0)
            q.push(w);

        q.pop();
      }

      return res.size() == n ? res : vector<int>{};
    }
};

int main() {
  EXECS(Solution::findOrder);
  EXECS(Solution::findOrderBFS);
  return 0;
}