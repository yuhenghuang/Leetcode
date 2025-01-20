#include "utils2.hpp"

class Solution {
  public:
    int romanToInt(string s) {
      unordered_map<char, int> m {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
      };

      int res = m[s[0]];
      for (size_t i=1; i<s.size(); ++i) {
        if (m[s[i-1]] < m[s[i]])
          res -= m[s[i-1]] << 1;
        
        res += m[s[i]];
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::romanToInt);
  return 0;
}