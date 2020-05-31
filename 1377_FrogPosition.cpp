#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
  public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
      vector<vector<int>> graph(n+1);
      vector<double> prob(n+1, 0);
      vector<double> prev(n+1, 0);
      vector<bool> seen(n+1, false);
      
      for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      graph[0].push_back(1);
      queue<int> q;
      q.push(0);
      seen[0] = true;
      prev[0] = 1.;
      ++t;

      while (t-- && !q.empty()) {
        int N = q.size();
        vector<double> next(n+1, 0);
        while (N--) {
          int v = q.front(); q.pop();
          int s = 0;
          for (int& w : graph[v]) 
            if (!seen[w])
              ++s;
          if (s==0)
            prob[v] = prev[v];
          else {
            double p = prev[v] / s;
            for (int& w : graph[v]) {
              if (seen[w]) continue;
              seen[w] = true;
              q.push(w);
              next[w] = p;
            }
          }
        }
        prev = next;
      }
      return max(prob[target], prev[target]);
    }
};

int main() {
  vector<vector<int>> arg = {{1,2}, {1,3}, {1,7}, {2,4}, {2,6}, {3,5}};
  Solution sol;
  cout << sol.frogPosition(7, arg, 20, 6) << endl;
  return 0;
}