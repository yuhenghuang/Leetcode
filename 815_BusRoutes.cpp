#include "utils.hpp"
#include <algorithm>
#include <queue>

class Solution {
  private:
    static bool intersect(const vector<int>& A, const vector<int>& B) {
      if (A.back() < B.front() || A.front() > B.back()) return false;

      int i=0, j=0;
      while (i<A.size() && j<B.size()) {
        if (A[i]==B[j]) return true;
        if (A[i]<B[j])
          ++i;
        else
          ++j;
      }
      return false;
    }
  public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
      if (S==T) return 0;

      int n = routes.size();
      for (vector<int>& bus : routes) 
        sort(bus.begin(), bus.end());

      bool flag;
      vector<vector<int>> graph(n);
      for (int i=1; i<n; ++i) {
        for (int j=0; j<i; ++j) {
          /*
          for (int& stop : routes[i]) {
            flag = false;
            if (binary_search(routes[j].begin(), routes[j].end(), stop)) {
              flag = true;
              break;
            }
          }
          */

          flag = intersect(routes[i], routes[j]);
          if (flag) {
            graph[i].push_back(j);
            graph[j].push_back(i);
          }
        }
      }

      queue<int> q;
      vector<bool> seen(n, false);
      vector<bool> dest(n, false);
      for (int i=0; i<n; ++i) {
        if (binary_search(routes[i].begin(), routes[i].end(), T))
          dest[i] = true;

        if (binary_search(routes[i].begin(), routes[i].end(), S)) {
          seen[i] = true;
          q.push(i);
        }
      }

      int res = 1;

      int N, bus;
      while (!q.empty()) {
        N = q.size();
        while (N--) {
          bus = q.front();
          q.pop();
          if (dest[bus]) return res;
          for (const int& w : graph[bus]) 
            if (!seen[w]){
              q.push(w);
              seen[w] = true;
            }
        }
        ++res;
      }
      return -1;
    }
};


int main() {
  UFUNC(Solution::numBusesToDestination);
  return 0;
}