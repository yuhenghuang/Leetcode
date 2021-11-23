#include <unordered_set>
#include "utils3.hpp"

class Solution {
  public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
      // id, active minutes
      unordered_map<int, unordered_set<int>> m;

      for (auto& log : logs)
        m[log[0]].insert(log[1]);

      vector<int> res(k);
      for (auto& p : m)
        ++res[p.second.size() - 1];

      return res;
    }
};


int main() {
  UFUNCS(Solution::findingUsersActiveMinutes);
  return 0;
}