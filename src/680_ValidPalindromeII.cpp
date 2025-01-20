#include <local_leetcode.hpp>

class Solution {
  private:
    bool isPalindrome(const string& s, int i, int j) {
      while (i < j) 
        if (s[i++] != s[j--])
          return false;

      return true;
    }

  public:
    bool validPalindrome(string s) {
      int i = 0, j = static_cast<int>(s.size()) - 1;

      while (i < j)
        if (s[i++] != s[j--])
          return isPalindrome(s, i, j+1) || isPalindrome(s, i-1, j);

      return true;
    }
};


int main() {
  EXECS(Solution::validPalindrome);
  return 0;
}