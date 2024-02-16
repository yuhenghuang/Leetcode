#include <local_leetcode.hpp>

class Solution {
  public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());

      const int n = s.size();
      
      int i = 0;

      for (int j = 0; i < g.size() and j < n; ++j) {
        for (; j < n and s[j] < g[i]; ++j);

        if (j < n) [[ likely ]]
          ++i;
      }

      return i;
    }
};


int main() {
  EXECS(Solution::findContentChildren);
  return 0;
}