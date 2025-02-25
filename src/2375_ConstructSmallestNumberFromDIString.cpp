#include <local_leetcode.hpp>

class Solution {
  private:
      void dfs(string_view p, string& res, vector<bool>& memo, string& s) {
        if (not res.empty())
          return;
        else if (p.empty()) {
          res = s;
          return;
        }
        
        const int d = s.back() - '1';
        const bool dec = p.front() == 'D';

        for (int i = 0; i < 9; ++i) 
          if (((dec and i < d) or (!dec and i > d)) and not memo[i]) {
            memo[i] = true;
            s.push_back('1' + i);
            dfs(p.substr(1, p.size() - 1), res, memo, s);
            s.pop_back();
            memo[i] = false;
          }
      }

  public:
    string smallestNumber(string pattern) {
      string res;

      string s;
      vector<bool> memo(10);

      for (int i = 0; i < 9; ++i) {
        memo[i] = true;
        s.push_back('1' + i);
        dfs(pattern, res, memo, s);
        s.pop_back();
        memo[i] = false;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::smallestNumber);
  return 0;
}
