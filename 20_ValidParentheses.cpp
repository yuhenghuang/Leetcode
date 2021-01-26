#include "utils.hpp"

class Solution {
  public:
    bool isValid(string s) {
      stack<char> st;

      static unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
      // m.emplace('(', ')');
      // m.emplace('[', ']');
      // m.emplace('{', '}');

      for (const char c : s) {
        if (m.count(c)){
          if (st.empty() || m[c]!=st.top())
            return false;
          st.pop();
        }
        else 
          st.push(c);
      }

      return st.empty();
    }
};


int main() {
  UFUNC(Solution::isValid);
  return 0;
}