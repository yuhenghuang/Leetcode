#include <local_leetcode.hpp>

class Solution {
  private:
    void pathToBob(int u, int v, int bob, const vector<vector<int>>& tree, vector<int>& s, vector<int>& path) {
      if (v == bob)
        path = s;
      else if (not path.empty())
        return;

      for (int w : tree[v])
        if (w != u) {
          s.push_back(w);
          pathToBob(v, w, bob, tree, s, path);
          s.pop_back();
        }
        
    }

  public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
      const int n = edges.size() + 1;

      vector<vector<int>> tree(n);
      for (auto& e : edges) {
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
      }

      vector<int> s{0}, path;
      pathToBob(-1, 0, bob, tree, s, path);

      const int m = path.size();
      for (int i = (m + 1) / 2; i < m; ++i)
        amount[path[i]] = 0;

      if (m & 1) 
        amount[path[m/2]] /= 2;

      int res = INT_MIN;

      // u, v, profit until v (include v)
      queue<tuple<int, int, int>> q;
      q.emplace(-1, 0, amount[0]);

      while (not q.empty()) {
        auto [u, v, p] = q.front();
        q.pop();

        vector<int>& ws = tree[v];

        // leaf node
        if (ws.size() == 1 and v != 0)
          res = max(res, p);
        else {
          for (int w : ws)
            if (w != u)
              q.emplace(v, w, p + amount[w]);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::mostProfitablePath);
  return 0;
}