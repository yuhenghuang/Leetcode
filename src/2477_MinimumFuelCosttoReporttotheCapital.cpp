#include <local_leetcode.hpp>

class Solution {
  private:
    int div_ceiling(int a, int b) {
      return a / b + ((a % b) ? 1 : 0);
    }

    pair<int, int64_t> dfs(int u, int v, const int seats, const vector<vector<int>>& tree) {
      pair<int, int64_t> res {1, 0}; // num. of representatives, fuels

      for (const int& w : tree[v]) // child
        if (w != u) {
          auto&& [reps, fuels] = dfs(v, w, seats, tree);
          res.first += reps;
          res.second += fuels + div_ceiling(reps, seats);
        }

      return res;
    }

  public:
    long long minimumFuelCostDFS(vector<vector<int>>& roads, int seats) {
      int n = roads.size() + 1;

      vector<vector<int>> tree(n);
      for (auto& r : roads) {
        tree[r[0]].push_back(r[1]);
        tree[r[1]].push_back(r[0]);
      }

      return dfs(-1, 0, seats, tree).second;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
      // traverse in topological order
      // from leaf to root(0)

      int n = roads.size() + 1;

      vector<int> degrees(n);
      vector<vector<int>> tree(n);
      for (auto& r : roads) {
        tree[r[0]].push_back(r[1]);
        tree[r[1]].push_back(r[0]);

        ++degrees[r[0]];
        ++degrees[r[1]];
      }

      vector<bool> seen(n);
      queue<int> q;

      // initialize queue with leaves
      for (int i = 1; i < n; ++i)
        if (degrees[i] == 1) {
          q.push(i);
          seen[i] = true;
        }

      vector<int> reps(n, 1); // num. of representatives in each city

      // use int64_t for cross-platform compatibility
      int64_t res = 0;

      while (!q.empty()) {
        int c = q.front(); // child
        q.pop();

        // update result by fuels needed to transport representatives in child to parent
        res += div_ceiling(reps[c], seats);

        for (const int& p : tree[c]) // parent
          if (!seen[p]) {
            reps[p] += reps[c];

            if (p != 0 && --degrees[p] == 1) {
              q.push(p);
              seen[p] = true;
            }
          }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumFuelCost);
  EXECS(Solution::minimumFuelCostDFS);
  return 0;
}