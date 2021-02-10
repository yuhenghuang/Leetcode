#include "utils2.hpp"

class Solution {
  private:
    int find(const vector<int>& parent, int e) {
      while (parent[e]!=e)
        e = parent[e];
      return e;
    }

  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      vector<int> parent(n+1);
      for (int i=1; i<=n; ++i)
        parent[i] = i;

      // edges triggered circle or doubled edge
      vector<int> circle, edge1, edge2;
      for (vector<int>& e : edges) {
        int x = find(parent, e[0]);
        int y = find(parent, e[1]);
        // circle found
        if (x==y) {

          // if circle found, meaning edge1 is the wrong choice
          if (!edge1.empty())
            return edge1;

          circle.push_back(e[0]);
          circle.push_back(e[1]);
        }
        // doubled edges found
        else if (y != e[1]) {
          edge1.push_back(parent[e[1]]);
          edge1.push_back(e[1]);

          // if circle found, meaning edge1 is the wrong choice
          if (!circle.empty())
            return edge1;

          edge2.push_back(e[0]);
          edge2.push_back(e[1]);
        }
        // construct graph normally
        // for double edges, always try only edge1
        else
          parent[e[1]] = e[0];
      }

      // resolve double edges problem first
      return edge2.empty() ? circle : edge2;
    }
};


int main() {
  UFUNC(Solution::findRedundantDirectedConnection);
  return 0;
}