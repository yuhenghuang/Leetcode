#include "utils2.hpp"

class Solution {
  private:
    bool isPalindromic(const string& s) {
      size_t n = s.length();
      for (size_t i = 0; i < n/2; ++i)
        if (s[i] != s[n-1-i])
          return false;
        
      return true;
    }
  
  public:
    int removePalindromeSub(string s) {
      if (s.length() == 0)
        return 0;
      else if (isPalindromic(s))
        return 1;
      else
        return 2;
    }
};


int main() {
  UFUNC(Solution::removePalindromeSub);
  return 0;
}