#include <local_leetcode.hpp>

enum STATUS {
  UNCHARTED = 0,
  VISITED_1 = 1,
  VISITED_2 = 2,
  BOTH_VISITED = 3
};

STATUS& operator|=(STATUS& lhs, STATUS rhs) {
  lhs = STATUS((int)lhs | (int)rhs);
  return lhs;
}

class Solution {
  public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      vector<STATUS> status(edges.size());

      while ((status[node1] & VISITED_1) == UNCHARTED || (status[node2] & VISITED_2) == UNCHARTED) {
        int res = INT_MAX;
        if ((status[node1] & VISITED_1) == UNCHARTED) {
          if ((status[node1] |= VISITED_1) == BOTH_VISITED)
            res = node1;
          
          // move one step if possible
          if (edges[node1] >= 0)
            node1 = edges[node1];
        }

        if ((status[node2] & VISITED_2) == UNCHARTED) {
          if ((status[node2] |= VISITED_2) == BOTH_VISITED)
            res = min(res, node2);

          if (edges[node2] >= 0)
            node2 = edges[node2];
        }

        if (res < INT_MAX)
          return res;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::closestMeetingNode);
  return 0;
}