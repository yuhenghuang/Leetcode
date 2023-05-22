#include <local_leetcode.hpp>

class Solution {
  private:
    enum COLOR {BLACK, WHITE, GREY};

    bool possible;

    void dfs(int v, vector<COLOR>& state, const vector<vector<int>>& graph) {
      if (!possible)
        return;

      COLOR c = state[v] == BLACK ? WHITE : BLACK;

      for (int w : graph[v]) {
        if (state[w]==c)
          continue;
        else if (state[w]==GREY) {
          state[w] = c;
          dfs(w, state, graph);
        }
        else
          possible = false;
      }
    }

  public:
    bool isBipartite(vector<vector<int>>& graph) {
      possible = true;

      int n = graph.size();
      vector<COLOR> state(n, GREY);

      for (int i=0; i<n; ++i)
        if (state[i] == GREY) {
          state[i] = BLACK;
          dfs(i, state, graph);
        }

      return possible;
    }
};


int main() {
  EXECS(Solution::isBipartite);
  return 0;
}