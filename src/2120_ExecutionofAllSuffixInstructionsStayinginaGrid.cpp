#include <local_leetcode.hpp>

class Solution {
  private:
    int dfs(int i, int j, const char* w, int n) {
      if (i < 0 || i >= n || j < 0 || j >= n)
        return -1;
      else if (*w == '\0')
        return 0;
        
      switch (*w++) {
        case 'D':
          ++i; break;
        case 'U':
          --i; break;
        case 'R':
          ++j; break;
        case 'L':
          --j; break;
        default:
          abort();
      }

      return 1 + dfs(i, j, w, n);
    }

  public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
      vector<int> res;
      res.reserve(s.size());
      for (const char* w = s.c_str(); *w != '\0'; ++w)
        res.push_back(dfs(startPos[0], startPos[1], w, n));

      return res;
    }
};


int main() {
  EXECS(Solution::executeInstructions);
  return 0;
}