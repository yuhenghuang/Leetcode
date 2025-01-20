#include <local_leetcode.hpp>

class Solution {
  public:
    int uniqueLetterString(string s) {
      pair<int, int> index[26];
      memset(index, -1, sizeof(index));

      int res = 0;
      int curr = 0;

      for (int i = 0; i < s.size(); ++i) {
        // k : second last index of s[i]
        // j : last index of s[i]
        auto& [k, j] = index[s[i] - 'A'];

        // increment by i - j substrings (s[i] added to unique chars)
        // decrement by j - k substrings (s[i] removed from unique chars)
        curr += i - j - (j - k);
        
        res += curr;

        k = j;
        j = i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::uniqueLetterString);
  return 0;
}