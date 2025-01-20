#include <local_leetcode.hpp>

class Solution {
  private:
    bool isupper(char ch) {
      return std::isupper(static_cast<unsigned char>(ch));
    }

  public:
    bool detectCapitalUse(string word) {
      int n = word.size();

      if (n < 2)
        return true;

      bool is_capital = isupper(word[1]);
      for (int i = 2 ; i < n; ++i)
        if (isupper(word[i]) != is_capital)
          return false;

      return (isupper(word[0]) == is_capital) || (isupper(word[0]) && !is_capital);
    }
};


int main() {
  EXECS(Solution::detectCapitalUse);
  return 0;
}