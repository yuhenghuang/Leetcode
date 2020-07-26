#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
 
enum COLOR {WHITE, GREY, BLACK};

class Solution {
  private:
    vector<COLOR> clr;
    vector<vector<int>> graph;
    vector<int> res;
    bool flag;
    int idx;
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      graph.resize(numCourses);

      for (auto& pre : prerequisites)
        graph[pre[1]].push_back(pre[0]);

      idx = numCourses;
      flag = false;
      res.resize(numCourses);
      clr = vector<COLOR>(numCourses, WHITE);

      for (int i=0; i<numCourses; ++i)
        if (clr[i]==WHITE)
          dfs(i);

      if (flag)
        return {};
      else 
        return res;
    }

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
};

int main() {
  Solution sol;
  vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<int> res = sol.findOrder(4, edges);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}