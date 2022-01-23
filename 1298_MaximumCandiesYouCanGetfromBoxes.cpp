#include <local_leetcode.hpp>

class Solution {
  public:
    int maxCandies(vector<int>& status, 
                   vector<int>& candies, 
                   vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) 
    {
      // 1: visited only 2: key only 3: key and visited
      vector<int> seen(status.size());

      queue<int> q;
      for (const int& v : initialBoxes) {
        if (status[v] == 1) {
          seen[v] = 3;
          q.push(v);
        }
        else 
          seen[v] = 1;
      }

      int res = 0;
      while (!q.empty()) {
        int v = q.front();
        q.pop();

        res += candies[v];
        for (const int& k : keys[v]) {
          if (seen[k] == 1) {
            q.push(k);
            // avoid multiple key?
            seen[k] = 3;
          }
          else {
            seen[k] |= 2;
            status[k] = 1;
          }
        }

        for (const int& w : containedBoxes[v])
          if (status[w] == 1 || seen[w] == 2) {
            q.push(w);
            // no necessary because a box won't be visited twice
            // seen[k] = 3;
          }
          else
            seen[w] = 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxCandies);
  return 0;
}