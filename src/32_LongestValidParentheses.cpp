#include <local_leetcode.hpp>

class Solution {
  public:
    int longestValidParentheses(string s) {
      int n = s.size();

      // size of longest valid parentheses whose right end is at index i
      vector<int> memo(n, 0);
      
      int res = 0;
      for (int i = 1; i < n; ++i) {

        if (s[i] == ')' && i-1-memo[i-1] >= 0 && s[i-1-memo[i-1]] == '(')
          memo[i] = memo[i-1] + 2;

        // concatenate, i.e. (...) + (...)
        int j = i - memo[i];
        if (j >= 0 && memo[j] > 0)
          memo[i] += memo[j];
          
        // cout << i << " " << memo[i] << endl;
        res = max(res, memo[i]);
      }
      return res;
    }
};


int main() {
  EXECS(Solution::longestValidParentheses);
  return 0;
}