#include <local_leetcode.hpp>

struct TrieNode {
  unordered_map<TrieNode*, double> children;

  TrieNode() {}
};

class Solution {
  private:
    unordered_map<string, TrieNode*> root;
    unordered_map<TrieNode*, bool> seen;

    double dfs(TrieNode* curr, TrieNode* target) {
      if (curr==target) return 1.0;
      seen[curr] = true;

      double res=-1.0;
      for (auto& iter : curr->children) {
        if (seen[iter.first]) continue;

        res = iter.second * dfs(iter.first, target);
        if (res>0)
          break;
      }

      seen[curr] = false;
      return res > 0 ? res : -1.0;
    }

    void reset() {
      root.clear();
      seen.clear();
    }

    double dfs(int u, int t, const vector<vector<int>>& graph, const vector<vector<double>>& weight , vector<bool>& seen) {
      if (u == t)
        return 1.0;

      seen[u] = true;

      double res = -1.0;
      for (auto& v : graph[u])
        if (!seen[v]) {
          res = weight[u][v] * dfs(v, t, graph, weight, seen);

          if (res > 0)
            break;
        }

      seen[u] = false;

      return res > 0 ? res : -1.0;
    }

  public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      reset();

      vector<double> res;
      res.reserve(queries.size());

      int n = equations.size();
      TrieNode *a, *b;
      for (int i=0; i<n; ++i) {
        if (root.find(equations[i][0])==root.end())
          root[equations[i][0]] = new TrieNode();
        a = root[equations[i][0]];
        if (root.find(equations[i][1])==root.end())
          root[equations[i][1]] = new TrieNode();
        b = root[equations[i][1]];

        a->children[b] = values[i];
        b->children[a]=1.0/values[i];
      }



      for (auto& p : queries) {
        if (root.find(p[0])==root.end() || root.find(p[1])==root.end())
          res.push_back(-1.0);
        else {
          a = root[p[0]];
          b = root[p[1]];
          res.push_back(dfs(a, b));
        }
      }

      return res;
    }

    vector<double> calcEquationPO(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      unordered_map<string, int> m;

      int uid = 0;
      for (auto& eq : equations)
        for (auto& var : eq) {
          if (m.count(var) == 0)
            m[var] = uid++;
        }

      int n = m.size();
      vector<vector<int>> graph(n);

      vector<vector<double>> weight(n, vector<double>(n));

      for (int i = 0; i < equations.size(); ++i) {
        int u = m[equations[i][0]];
        int v = m[equations[i][1]];
      
        graph[u].push_back(v);
        graph[v].push_back(u);

        weight[u][v] = values[i];
        weight[v][u] = 1 / values[i];
      }

      vector<bool> seen(n);

      vector<double> res;
      res.reserve(queries.size());

      for (auto& q : queries) {
        auto iter = m.find(q[0]);
        int u = iter == m.end() ? -1 : iter->second;

        iter = m.find(q[1]);
        int v = iter == m.end() ? -1 : iter->second;

        if (u >= 0 && v >= 0)
          res.push_back(dfs(u, v, graph, weight, seen));
        else
          res.push_back(-1.0);
      }

      return res;
    }
};


int main() {
  /*
  Solution sol;

  vector<string> args;
  vector<vector<string>> eqs, queries;
  vector<double> vals, res;

  utils::parse_vector_1d<double> parser_dbl;
  utils::parse_vector_2d<string> parser_str;

  ifstream f("Inputs/399_EvaluateDivision.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    eqs = parser_str(args[0]);
    vals = parser_dbl(args[1]);
    queries = parser_str(args[2]);

    res = sol.calcEquation(eqs, vals, queries);
    sol.reset();

    utils::print_vector_1d(res);
  }
  */

  EXECS(Solution::calcEquationPO);

  return 0;
}
