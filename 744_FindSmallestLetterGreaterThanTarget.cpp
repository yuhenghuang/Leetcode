#include <local_leetcode.hpp>

class Solution {
  public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      const int n = letters.size();

      int l = 0, r = n;
      while (l < r) {
        int m = l + (r - l) / 2;

        if (letters[m] <= target)
          l = m + 1;
        else
          r = m;
      }

      return letters[l % n];
    }
};


int main() {
  EXECS(Solution::nextGreatestLetter);
  return 0;
}