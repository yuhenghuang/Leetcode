#include "utils2.hpp"

class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<int> s;
      for (const string& t : tokens) {
        if (t.size() > 1 || isdigit(t[0])) {
          s.push(stoi(t));
        }
        else {
          int r = s.top(); s.pop();
          int l = s.top(); s.pop();
          int res;
          switch (t[0]) {
            case '+': res = l + r; break;
            case '-': res = l - r; break;
            case '*': res = l * r; break;
            case '/': res = l / r; break;
            default: return -1;
          }
          s.push(res);
        }
      }

      return s.top();
    }
};


int main() {
  UFUNC(Solution::evalRPN);
  return 0;
}