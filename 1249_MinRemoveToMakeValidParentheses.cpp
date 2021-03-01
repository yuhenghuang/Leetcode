#include "utils2.hpp"

class Solution {
  public:
    string minRemoveToMakeValid(string s) {
      int n = s.size();

      stack<char> st;
      string res;
      int right = 0;
      for (int i=n-1; i>=0; --i) {
        if (s[i]==')')
          ++right;
        else if (s[i]=='(') {
          if (right>0)
            --right;
          else 
            continue;
        }

        st.push(s[i]);
      }

      int left = 0;
      while (!st.empty()) {
        char c = st.top(); st.pop();
        if (c=='(')
          ++left;
        else if (c==')') {
          if (left>0)
            --left;
          else
            continue;
        }

        res.push_back(c);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::minRemoveToMakeValid);
  return 0;
}