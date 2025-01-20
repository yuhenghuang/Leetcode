#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>

class Solution {
  private:
    int res;
    vector<vector<int>> map;

    bool dfs(int prev, int cur, vector<bool>& hasApple) {
      bool flag = false;
      for (int& next : map[cur]) 
        if (next!=prev && dfs(cur, next, hasApple)) {
          flag = true;
          res += 2;
        }
      return flag || hasApple[cur];
    }

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

    int minTimeBFS(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      // # of connections to vertex i
      vector<int> connections(n);

      vector<vector<int>> tree(n);
      for (auto& e : edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);

        ++connections[e[0]];
        ++connections[e[1]];
      }

      vector<bool> seen(n);

      queue<int> q;

      // push leaves to queue
      for (int i = 1; i < n; ++i)
        if (connections[i] == 1) {
          q.push(i);
          seen[i] = true;
        }

      int res = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v != 0 && hasApple[v])
          res += 2;

        for (const int& u : tree[v]) {
          if (!seen[u]) {
            seen[u] = true;
            q.push(u);
          }

          // update parent to has apple
          if (hasApple[v])
            hasApple[u] = true;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minTime);
  EXECS(Solution::minTimeBFS);
  return 0;
}
