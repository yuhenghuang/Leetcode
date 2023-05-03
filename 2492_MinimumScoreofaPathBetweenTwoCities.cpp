#include <local_leetcode.hpp>

class Solution {
  public:
    int minScore(int n, vector<vector<int>>& roads) {
      // equivalent to finding the shortest edge on the subgraph where there are start and end

      vector<int> rank(n);
      vector<int> parent(n, -1);

      function<int (int)> find = [&parent, &find] (int p) -> int {
        if (parent[p] == -1)
          return p;
        return parent[p] = find(parent[p]);
      };

      function<void (int, int)> join = [&parent, &rank, &find] (int p, int q) {
        p = find(p);
        q = find(q);

        if (p != q) {
          if (rank[p] > rank[q])
            parent[q] = p;
          else if (rank[p] < rank[q])
            parent[p] = q;
          else {
            ++rank[p];
            parent[q] = p;
          }
        }
      };

      for (auto& road : roads)
        join(road[0] - 1, road[1] - 1);

      int p = find(0); // parent node of the subgraph containing start (and end by definition)
      int res = INT_MAX;

      for (auto& road : roads)
        // 1. road is an edge of the subgraph containing start and end
        // 2. distance of road is less than current result
        if (find(road[0] - 1) == p && road[2] < res)
          res = road[2];

      return res;
    }
};


int main() {
  EXECS(Solution::minScore);
  return 0;
}