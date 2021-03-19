#include "utils2.hpp"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      
      vector<bool> visited(n);
      visited[0] = true;

      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : rooms[v])
          if (!visited[w]) {
            visited[w] = true;
            q.push(w);
          }
      }
      
      for (bool b : visited)
        if (!b)
          return false;
      
      return true;
    }
};


int main() {
  UFUNC(Solution::canVisitAllRooms);
  return 0;
}