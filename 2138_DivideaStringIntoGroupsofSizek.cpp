#include <local_leetcode.hpp>

class Solution {
  public:
    vector<string> divideString(string s, int k, char fill) {
      int n = s.size();

      vector<string> res;
      for (int i = 0; i < n; i += k) 
        res.emplace_back(s.c_str() + i, s.c_str() + min(i + k, n));

      if (res.back().size() < k)
        res.back() += string(k - res.back().size(), fill);

      return res;
    }
};


int main() {
  EXECS(Solution::divideString);
  return 0;
}