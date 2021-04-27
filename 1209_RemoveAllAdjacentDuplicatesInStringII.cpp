#include "utils2.hpp"

class Solution {
  public:
    string removeDuplicates(string str, int k) {
      stack<pair<char, int>> s;
      int n = str.size();
      
      int i = 0;
      while (i < n) {        
        if (s.empty() || s.top().first != str[i])
          s.emplace(str[i], 1);
        else 
          s.top().second++;
        
        if (!s.empty() && s.top().second == k)
          s.pop();
        
        ++i;
      }
      
      string res;
      while (!s.empty()) {
        res += string(s.top().second, s.top().first);
        s.pop();
      }
      
      reverse(res.begin(), res.end());
      return res;
    }
};


int main() {
  UFUNC(Solution::removeDuplicates);
  return 0;
}