#define _NONTRIVIAL_SOLUTION_CTOR
#include "utils3.hpp"

class Solution {
  private:
    int target;
    vector<int> stack;
    vector<vector<int>> res;
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      target = graph.size() - 1;
      stack.push_back(0);
      dfs(graph);
      return res;
    }

    void dfs(vector<vector<int>>& graph) {
      if (stack.back()==target) {
        res.push_back(stack);
        return;
      }

      for (int w : graph[stack.back()]) {
        stack.push_back(w);
        dfs(graph);
        stack.pop_back();
      }
    }
};

int main() {
  UFUNCS(Solution::allPathsSourceTarget);
  return 0;
}