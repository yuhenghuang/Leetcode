#include "utils3.hpp"

class Solution {
  public:
    int characterReplacement(string s, int k) {
      int n = s.size();

      int res = 0;

      for (int l = 0; l < 26; ++l) {
        char c = 'A' + l;
        int count = 0;

        int i = 0, j = 0;
        while (j < n) {
          if (j - i <= count + k) {
            if (s[j++] == c)
              ++count;

            if (j - i <= count + k && j - i > res)
              res = j - i;
          }
          else {
            if (s[i++] == c)
              --count;
          }
        }
      }

      return res;
    }

    int characterReplacementFast(string s, int k) {
      int n = s.size();

      int res = 0;

      int count[26] = {0};

      int max_count = 0;
      int i = 0, j = 0;
      for (; j < n; ++j) {
        // max_count is not necessarily the right max count
        // as long as wrong max_count can trigger
        // the following if, its job is done. 
        max_count = max(max_count, ++count[s[j] - 'A']);

        // since max_count at most grows by 1 each time
        // no matter max_count is right or wrong,
        // if we move i by 1 each time
        // the result won't change
        if (j - i + 1 > max_count + k)
          --count[s[i++] - 'A'];

        res = max(res, j - i + 1);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::characterReplacement);
  UFUNCS(Solution::characterReplacementFast);
  return 0;
}