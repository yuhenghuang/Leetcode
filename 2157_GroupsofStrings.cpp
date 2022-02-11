#include <local_leetcode.hpp>

class Solution {
  private:
    int dfs(int u, vector<bool>& seen, const vector<int>& count, const vector<vector<int>>& graph) {
      if (seen[u])
        return 0;

      seen[u] = true;

      int res = count[u];
      for (const int& v : graph[u])
        res += dfs(v, seen, count, graph);

      return res;
    }

  public:
    vector<int> groupStrings(vector<string>& words) {
      int uid = 0;

      // bits, uid
      unordered_map<int, int> m;

      // uid, count
      vector<int> count;

      vector<vector<int>> graph;
      for (auto& word : words) {

        int bits = 0;
        for (char c : word)
          bits |= 1 << (c - 'a');

        unordered_map<int, int>::iterator iter = m.find(bits);

        // bits already found
        if (iter != m.end()) {
          ++count[iter->second];
          continue;
        }

        // update graph and count
        graph.emplace_back();
        count.push_back(1);

        for (int i = 0; i < 26; ++i) {
          // add or delete
          iter = m.find(bits ^ (1 << i));
          if (iter != m.end()) {
              graph[uid].push_back(iter->second);
              graph[iter->second].push_back(uid);
            }

          // replace i by j
          if ((bits >> i) & 1) {
            for (int j = 0; j < 26; ++j)
              if (((bits >> j) & 1) == 0) {
                iter = m.find(bits ^ ((1 << i) | (1 << j)));
                if (iter != m.end()) {
                    graph[uid].push_back(iter->second);
                    graph[iter->second].push_back(uid);
                }
              }
          }
        }

        m[bits] = uid++;
      }

      vector<bool> seen(uid);

      int groups = 0;
      int size = 0;
      for (int i = 0; i < uid; ++i) {
        // size of subgraph
        int s = dfs(i, seen, count, graph);
        if (s > 0) {
          ++groups;
          size = max(size, s);
        }
      }

      return {groups, size};
    }
};


int main() {
  EXECS(Solution::groupStrings);
  return 0;
}