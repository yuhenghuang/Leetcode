#include <local_leetcode.hpp>

class Solution {
  private:
    bool isVowel(char c) {
      if (!isalpha(c))
        return false;

      if (isupper(c))
        c += 32;

      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    string reverseVowels(string s) {
      int i = 0, j = (int) s.size() - 1;

      while (i < j) {
        for (; i < j && !isVowel(s[i]); ++i);

        for (; i < j && !isVowel(s[j]); --j);

        if (i < j && s[i] != s[j])
          swap(s[i], s[j]);

        ++i;
        --j;
      }

      return s;
    }
};


int main() {
  EXECS(Solution::reverseVowels);
  return 0;
}