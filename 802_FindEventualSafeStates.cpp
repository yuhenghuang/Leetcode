#include <local_leetcode.hpp>

class Solution {
  private:
    enum COLORS {
      WHITE,
      GREY,
      SAFE,
      UNSAFE
    };

    // return true if SAFE
    bool dfs(int u, vector<COLORS>& clrs, const vector<vector<int>>& graph) {
      if (clrs[u] == GREY)
        return false;
      else if (clrs[u] != WHITE)
        return clrs[u] == SAFE;

      clrs[u] = GREY;

      bool flag = true;
      for (int v : graph[u])
        flag &= dfs(v, clrs, graph);

      clrs[u] = flag ? SAFE : UNSAFE;

      return flag;
    }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      const int n = graph.size();

      vector<COLORS> clrs(n);

      for (int i = 0; i < n; ++i)
        if (clrs[i] == WHITE)
          dfs(i, clrs, graph);

      vector<int> res;
      for (int i = 0; i < n; ++i)
        if (clrs[i] == SAFE)
          res.push_back(i);
      
      return res;
    }
};


int main() {
  EXECS(Solution::eventualSafeNodes);
  return 0;
}