#include "utils3.hpp"

class Solution {
  private:
    int gcd(int a, int b) {
      if (b == 0)
        return a;
      else
        return gcd(b, a % b);
    }

    /**
     * @brief depth-first-search over the tree
     * 
     * 
     * @param u previous node, used to avoid traversing back.
     * @param v current node
     * @param depth depth from root
     * @param nums value in each node
     * @param graph undirected_graph in the form of 2D array
     * @param coprime coprime pairs
     * @param ancestors 1D array, index: node value, first: depth, second: node(int). only keeps most recent ancestor of each value
     * @param res result 1D array
     * 
     */
    void dfs(
      int u, int v, int depth, 
      vector<int>& nums, vector<vector<int>>& graph, vector<vector<int>>& coprime, 
      pair<int, int> (&ancestors) [51], vector<int>& res
    ) {
      // 
      int num = nums[v];

      int ans = -1, d = -1;
      for (int prime : coprime[num]) {
        pair<int, int>& p = ancestors[prime];
        if (p.first > d) {
          d = p.first;
          ans = p.second;
        }
      }

      res[v] = ans;

      // store latest occurence(depth) of $num$ and update it
      pair<int, int>& p = ancestors[num];
      pair<int, int> temp = p;
      p.first = depth;
      p.second = v;

      for (int w : graph[v])
        if (w != u) 
          dfs(v, w, depth+1, nums, graph, coprime, ancestors, res);

      // restore ancestors[num]
      p = temp;
    }

  public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
      int n = nums.size();

      vector<vector<int>> graph(n);
      for (vector<int>& e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      vector<vector<int>> coprime(51);

      for (int i = 1; i <= 50; ++i)
        for (int j = 1; j <= i; ++j) 
          if (gcd(i, j) == 1) {
            coprime[i].push_back(j);
            coprime[j].push_back(i);
          }

      // depth, node
      pair<int, int> ancestors[51];
      memset(ancestors, -1, sizeof(ancestors));

      vector<int> res(n);
      dfs(-1, 0, 0, nums, graph, coprime, ancestors, res);

      return res;
    }
};


int main() {
  UFUNCS(Solution::getCoprimes);
  return 0;
}