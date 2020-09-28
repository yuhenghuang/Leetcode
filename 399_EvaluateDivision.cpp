#include "utils.hpp"
#include <unordered_map>

using namespace std;

struct TrieNode {
  unordered_map<TrieNode*, double> dict;

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
      for (auto& iter : curr->dict) {
        if (seen[iter.first]) continue;

        res = iter.second * dfs(iter.first, target);
        if (res>0)
          break;
      }

      seen[curr] = false;
      return res > 0 ? res : -1.0;
    }

  public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
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

        a->dict[b] = values[i];
        b->dict[a]=1.0/values[i];
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

    void reset() {
      root.clear();
      seen.clear();
    }
};


int main() {
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

  return 0;
}
