#include <local_leetcode.hpp>

class Solution {
  private:
    enum COLOR {WHITE, BLACK, GREY};

    struct Node {
      COLOR color;

      bool circle; // is node on a circle
      bool chain; // is node on a chain with a circle of size 2 at end
      int id;
      int level;
      int length;

      Node(): color(WHITE), chain(false) { }
    };

    int uid;

    int dfs(int v, vector<int>& edge, vector<Node>& nodes) {
      Node& node = nodes[v];
      
      // visited node
      if (node.color == BLACK) {
        return node.chain ? node.length : 0;
      }

      node.color = GREY;
      node.level = node.id = uid++;

      Node& next = nodes[edge[v]];

      int len = 0;
      if (next.color == GREY) {
        node.level = next.level;
      }
      else if (next.color == BLACK) {
        len = dfs(edge[v], edge, nodes);
      }
      else {
        len = dfs(edge[v], edge, nodes);
        node.level = min(node.id, next.level);
      }
        
      node.circle = node.level == next.level;

      if (next.chain)
        node.chain = next.chain;
      // node in a circle
      // node is the first one searched in the circle
      // size of circle is 1 (without node)
      else if (node.circle && node.id == node.level && len == 1) {
        node.chain = next.chain = true;
      }

      if (node.circle || node.chain)
        ++len;

      node.color = BLACK;

      return node.length = len;
    }

  public:
    int maximumInvitations(vector<int>& favorite) {
      // wrong answer

      uid = 0;

      int n = favorite.size();

      vector<Node> nodes(n);

      int res = 0; // longest circle or chain
      for (int i = 0; i < n; ++i)
        res = max(res, dfs(i, favorite, nodes));

      int tmp = 0; // combination of all chains
      for (int i = 0; i < n; ++i)
        if (nodes[i].chain)
          ++tmp;

      return max(res, tmp);
    }
};


int main() {
  EXECS(Solution::maximumInvitations);
  return 0;
}