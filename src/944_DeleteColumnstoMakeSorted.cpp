#include <local_leetcode.hpp>

class Solution {
  public:
    int minDeletionSize(vector<string>& strs) {
      int m = strs[0].size();

      int res = 0;
      vector<bool> flags(m);
      for (int i = 1; i < (int) strs.size(); ++i) {
        string& s1 = strs[i-1];
        string& s2 = strs[i];
        for (int j = 0; j < m; ++j)
          if (!flags[j] && s1[j] > s2[j]) {
            ++res;
            flags[j] = true;
          }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minDeletionSize);
  return 0;
}