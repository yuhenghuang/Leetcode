#include <local_leetcode.hpp>

class Solution {
  private:
    int res;

    void dfs(const string& v, unordered_map<string, unordered_set<string>>& graph, unordered_set<string>& seen, int curr) {
      if (seen.count(v) > 0)
        return;

      seen.insert(v);

      if (graph.count(v) == 0) 
        res = max(res, curr);
      else {
        for (const string& w : graph[v])
          dfs(w, graph, seen, curr + 1);
      }
    }

  public:
    int longestStrChain(vector<string>& words) {
      vector<unordered_set<string>> buckets(17);

      for (string& w : words) {
        // sort(w.begin(), w.end());
        buckets[w.length()].insert(w);
      }

      unordered_map<string, unordered_set<string>> graph;
      for (int i = 2; i <= 16; ++i) {
        for (const string& w : buckets[i]) {
          for (int j = 0; j < w.size(); ++j) {
            string pred = w.substr(0, j) + w.substr(j+1, w.size() - j - 1);
            auto iter = buckets[i-1].find(pred);
            if (iter != buckets[i-1].end())
              graph[*iter].insert(w);
          }
        }
      }

      res = 0;
      unordered_set<string> seen;
      for (int i = 1; i <= 16; ++i)
        for (const string& s : buckets[i])
          if (seen.count(s) == 0)
            dfs(s, graph, seen, 1);

      return res;
    }

    int longestStrChainDP(vector<string>& words) {
      sort(words.begin(), words.end(),
        [](const string& x, const string& y) -> bool {
          return x.size() < y.size();
        }
      );

      int res = 0;
      unordered_map<string, int> memo;
      for (const string& w : words) {
        int temp = 0;
        for (int i = 0; i < w.size(); ++i) {
          string pred = w.substr(0, i) + w.substr(i+1, w.size() - i - 1);
          temp = max(temp, memo[pred]);
        }
        memo[w] = ++temp;
        res = max(res, temp);
      }

      return res;
    }
};


int main() {
    EXECS(Solution::longestStrChain);
    EXECS(Solution::longestStrChainDP);
  return 0;
}