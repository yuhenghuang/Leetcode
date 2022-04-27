#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      map<int, vector<int>, greater<int>> m;

      for (auto& p : properties)
        m[p[0]].push_back(p[1]);

      int res = 0;

      auto iter = m.begin();

      int def = *max_element(iter->second.begin(), iter->second.end());

      for (++iter; iter != m.end(); ++iter) {
        int temp = def;
        for (const int& d : iter->second) {
          if (d < def)
            ++res;
          else if (d > temp)
            temp = d;
        }

        // update current max defense
        def = temp;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numberOfWeakCharacters);
  return 0;
}