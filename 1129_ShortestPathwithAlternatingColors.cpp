#include <local_leetcode.hpp>

class Solution {
  private:
    enum COLOR {
      WHITE = 0,
      RED = 1,
      BLUE = 2,
      BLACK = 3
    };

    friend COLOR& operator|=(COLOR& lhs, COLOR rhs) {
      return lhs = static_cast<COLOR>(lhs | rhs); 
    }

  public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      vector<vector<int>> graphs[2]; // graphs of red and blue
      graphs[0].resize(n);
      graphs[1].resize(n);

      for (auto& e : redEdges)
        graphs[0][e[0]].push_back(e[1]);

      for (auto& e : blueEdges)
        graphs[1][e[0]].push_back(e[1]);

      // status of vertexes
      vector<COLOR> seen(n, WHITE);
      seen[0] = BLACK;

      // results
      vector<int> res(n, -1);
      res[0] = 0;

      queue<int> q;
      q.push(0); q.push(-1);

      int steps = 1;
      while (!q.empty()) {
        int N = q.size(); // size of current layer in BFS
        while (N--) {
          int u = q.front();
          q.pop();

          // color of current vertex u
          // u < 0 -> RED
          // u >= 0 -> BLUE
          COLOR clr = u < 0 ? RED : BLUE;

          // restore u to index in [0, n)
          if (u < 0)
            u = -u - 1;

          for (const int& v : graphs[clr - 1][u])
            if ((seen[v] & clr) == WHITE) {
              // update result only when next vertex v is visited first time
              if (seen[v] == WHITE)
                res[v] = steps;

              // update the status (color) of next vertex v and push it into queue
              seen[v] |= clr;
              q.push(clr == RED ? v : (-v - 1));
            }
        }

        ++steps;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::shortestAlternatingPaths);
  return 0;
}