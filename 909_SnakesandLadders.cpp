#include <local_leetcode.hpp>

class Solution {
  public:
    int snakesAndLadders(vector<vector<int>>& board) {
      // flatten board
      vector<int> route {0};

      bool flag = true;
      for(auto row = board.rbegin(); row != board.rend(); ++row) {
        if (flag)
          copy(row->begin(), row->end(), back_inserter(route));
        else
          copy(row->rbegin(), row->rend(), back_inserter(route));

        flag = !flag;
      }

      int n = (int) route.size() - 1;

      vector<bool> seen(n + 1);
      seen[1] = true;

      queue<int> q;
      q.push(1);

      int res = 0;

      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int u = q.front();
          q.pop();
          if (u == n)
            return res;

          for (int i = u + 1; i <= n && i <= u + 6; ++i) {
            // If next has a snake or ladder,
            // you must move to the destination of that snake or ladder.
            // Otherwise, you move to next
            int v = route[i] > 0 ? route[i] : i;

            if (!seen[v]) {
              q.push(v);
              seen[v] = true;
            }
          }
        }
        ++res;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::snakesAndLadders);
  return 0;
}