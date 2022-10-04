#include <local_leetcode.hpp>

class Solution {
  public:
    string reverseWords(string s) {
      auto iter = s.begin();
      while (iter != s.end()) {
        if (iter != s.begin())
          ++iter;

        auto eow = find(iter, s.end(), ' ');

        reverse(iter, eow);

        iter = eow;
      }

      return s;
    }
};


int main() {
  EXECS(Solution::reverseWords);
  return 0;
}