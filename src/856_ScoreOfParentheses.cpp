#include <local_leetcode.hpp>

class Solution {
  private:
    int dfs(const string& s, int& i) {
      int res = 0;

      while (i < s.size() && s[i] == '(') {
        // skip '(' at current level
        ++i;
        res += max(dfs(s, i) * 2, 1);
      }

      // skip ')'
      ++i;

      return res;
    }

  public:
    int scoreOfParentheses(string S) {
      stack<int> s;
      for (char c : S) {
        if (c == '(')
          s.push(0);
        else {
          if (s.top() == 0)
            s.top() = 1;
          else {
            int temp = 0;
            while (s.top() != 0) {
              temp += s.top();
              s.pop();
            }

            s.top() = temp * 2;
          }
        }
      }

      int res = 0;
      while (!s.empty()) {
        res += s.top();
        s.pop();
      }

      return res;
    }

    int scoreOfParenthesesDFS(string s) {
      int i = 0;

      return dfs(s, i);
    }
};


int main() {
  EXECS(Solution::scoreOfParentheses);
  EXECS(Solution::scoreOfParenthesesDFS);
  return 0;
}