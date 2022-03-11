#include <local_leetcode.hpp>

// element-wise operation
// write operator+= for array<...> to improve readability of `dfs(...)`
template <class Tp, size_t Size>
array<Tp, Size>& operator+=(array<Tp, Size>& lhs, const array<Tp, Size>& rhs) {
  transform(
    lhs.begin(), lhs.end(), 
    rhs.begin(), 
    lhs.begin(), 
    plus<Tp>()
  );

  return lhs;
}

class Solution {
  private:
    array<int, 26> dfs(int u, const vector<vector<int>>& graph, const string& labels, vector<bool>& seen, vector<int>& res) {
      seen[u] = true;

      // array is an aggregation type...
      array<int, 26> count {0};

      for (const int& v : graph[u])
        if (!seen[v]) 
          count += dfs(v, graph, labels, seen, res);

      res[u] = ++count[labels[u] - 'a'];

      return count;
    }

  public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
      vector<vector<int>> graph(n);
      for (auto& e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }

      vector<int> res(n);
      vector<bool> seen(n);

      dfs(0, graph, labels, seen, res);

      return res;
    }
};


int main() {
  EXECS(Solution::countSubTrees);
  return 0;
}