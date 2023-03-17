#include <local_leetcode.hpp>

class Solution {
  public:
    int minJumps(vector<int>& arr) {
      int n = arr.size();
      if (n==1) return 0;
      unordered_map<int, vector<int>> graph;
      for (int i=0; i<n; ++i)
        graph[arr[i]].push_back(i);
    
      vector<bool> seen(n, false);
      seen[0] = true;
      queue<int> q;
      q.push(0);
      int res=1;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front(); q.pop();

          if (v==n-2)
            return res;
          else if (!seen[v+1]) {
            seen[v+1];
            q.push(v+1);
          }

          if (v>0 && !seen[v-1]) {
            seen[v-1];
            q.push(v-1);
          }

          for (const int w : graph[arr[v]]) {
            if (seen[w]) continue;
            if (w==n-1) return res;
            seen[w] = true;
            q.push(w);
          }
          graph[arr[v]].clear();
        }
        ++res;
      }
      return res;
    }
};


int main() {
  EXECS(Solution::minJumps);
  return 0;
}