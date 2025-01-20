#include <local_leetcode.hpp>

class Solution {
  public:
    string countAndSay(int n) {
      if (n == 1) 
        return "1";

      string&& s = countAndSay(n - 1);

      typedef pair<char, int> ci_t;

      vector<ci_t> vec;
      vec.emplace_back(s.front(), 1);

      for (int i = 1; i < (int) s.size(); ++i)
        if (s[i-1] == s[i])
          ++vec.back().second;
        else
          vec.emplace_back(s[i], 1);

      string res;
      for (auto& [c, i] : vec)
        res += to_string(i) + c;

      return res;
    }
};


int main() {
  EXECS(Solution::countAndSay);
  return 0;
}