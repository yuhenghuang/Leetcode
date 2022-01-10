#include <local_leetcode.hpp>

class Solution {
  private:
    enum COLOR {WHITE, BLACK, GREY};

    struct Node {
      bool circle; // is node on a circle
      int chain; // is node on a chain with a circle of size 2 at end
      int id;
      int level;
      int length;
      COLOR color;

      Node(): color(WHITE), chain(-1) { }
    };

    int uid;

    int dfs(int v, vector<int>& edge, vector<Node>& nodes, vector<int>& side) {
      Node& node = nodes[v];

      if (node.color == BLACK) // visited node
        return nodes[node.level].length;

      node.color = GREY;
      node.level = node.id = uid++;

      Node& next = nodes[edge[v]];

      int len = 0;
      if (next.color == GREY) {
        node.level = next.level;
      }
      else if (next.color == BLACK) {
        len = dfs(edge[v], edge, nodes, side);
      }
      else {
        len = dfs(edge[v], edge, nodes, side);
        node.level = min(node.id, next.level);
      }
        
      node.circle = node.level == next.level;

      if (next.chain >= 0)
        node.chain = next.chain;
      else if (node.circle && node.id == node.level && len == 1) {
        node.chain = node.id;
        next.chain = next.id;

        side[next.chain] = 2;
      }

      if (node.circle || node.chain >= 0)
        ++len;

      if (node.chain >= 0)
        side[node.chain] = max(side[node.chain], len);

      node.color = BLACK;

      return node.length = len;
    }

  public:
    int maximumInvitations(vector<int>& favorite) {
      // wrong answer

      uid = 0;

      int n = favorite.size();

      vector<int> side(n);
      vector<Node> nodes(n);

      int res = 0;
      for (int i = 0; i < n; ++i)
        res = max(res, dfs(i, favorite, nodes, side));

      int temp = 0;
      for (int i = 0; i < n; ++i)
        if (i < favorite[i] && favorite[favorite[i]] == i) 
          temp += side[i] + side[favorite[i]] - 2;

      return max(res, temp);
    }
};


int main() {
  EXECS(Solution::maximumInvitations);
  return 0;
}