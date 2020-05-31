#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
      int N = s.size();
      vector<int> memo(N, 0);
      
      int res=0;
      for (int i=1; i<N; ++i) {

        if (s[i]==')' && i-1-memo[i-1]>=0 && s[i-1-memo[i-1]] == '(')
          memo[i] = memo[i-1] + 2;
        int idx = i - memo[i];
        while (idx>=0 && memo[idx]) {
          memo[i] += memo[idx];
          idx -= memo[idx];
        }
        cout << i << " " << memo[i] << endl;
        res = max(res, memo[i]);
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.longestValidParentheses("())") << endl;
}