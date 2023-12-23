#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
      unordered_set<int> s;
      unordered_map<int, pair<int, int>> m;

      for (auto& p : adjacentPairs) {
        int x = p[0], y = p[1];

        if (s.count(x))
          s.erase(x);
        else
          s.insert(x);

        if (s.count(y))
          s.erase(y);
        else
          s.insert(y);

        auto iter = m.find(x);
        if (iter == m.end())
          m[x] = {y, -1};
        else
          iter->second.second = y;

        iter = m.find(y);
        if (iter == m.end())
          m[y] = {x, INT_MIN};
        else
          iter->second.second = x;
      }

      int start = *s.begin();

      vector<int> res;
      res.push_back(start);
      res.push_back(m[start].first);

      for (int i = 1; i < adjacentPairs.size(); ++i) {
        auto& [u, v] = m[res[i]];

        res.push_back(u == res[i-1] ? v : u);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::restoreArray);
  return 0;
}