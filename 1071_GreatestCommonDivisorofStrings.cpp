#include <local_leetcode.hpp>

class Solution {
  public:
    string gcdOfStrings(string str1, string str2) {
      if (str1.size() < str2.size())
        return gcdOfStrings(str2, str1);
      else if (str2.empty())
        return str1;

      int m = str2.size();
      int n = (str1.size() / str2.size()) * str2.size();
      for (int i = 0; i < n; ++i)
        if (str1[i] != str2[i % m])
          return "";

      return gcdOfStrings(str2, str1.substr(n, str1.size() - n));
    }
};


int main() {
  EXECS(Solution::gcdOfStrings);
  return 0;
}