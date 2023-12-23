#include <local_leetcode.hpp>

class Solution {
  private:
    int countCompleteSubstrings(string_view sv, const int k) {
      const int n = sv.size();

      int res = 0;

      for (int t = 0; t < 26; ++t) {
        int duplicate = 0;
        int count[26] = {0};

        int i = 0;

        // find first index of char ('a' + t)
        for (; i < n and (sv[i] - 'a') != t; ++i);

        int j = i - 1;
        // find index j such that
        // in [i, j] there are exactly k char ('a' + t)
        // where char ('a' + t) is at index i and j
        for (; j + 1 < n and count[t] < k;) {
          ++j;
          
          int f = count[sv[j] - 'a']++;

          if (f == k or f == 0)
            ++duplicate;

          if (f + 1 == k)
            --duplicate;
        }

        // [i, j] is valid substring
        if (count[t] == k and duplicate == 0)
          ++res;

        while (j + 1 < n) {
          // expand from j + 1 to next char ('a' + t)
          for (; j + 1 < n and count[t] == k;) {
            ++j;

            int f = count[sv[j] - 'a']++;

            if (f == k or f == 0)
              ++duplicate;

            if (f + 1 == k)
              --duplicate;

            if (duplicate == 0)
              ++res;         
          }

          // update i to next char ('a' + t) if sv[j] is a valid new right bound
          if ((sv[j] - 'a') == t) {
            // move from i to next index where sv[i] is char ('a' + t)
            for (; count[t] > k or (sv[i] - 'a') != t; ++i) {
              int f = count[sv[i] - 'a']--;

              if (f == k)
                ++duplicate;

              if (f == 1 or f == k + 1)
                --duplicate;
            }

            // [i, j] is valid substring
            if (count[t] == k and duplicate == 0)
              ++res;
          }
        }
      }


      return res;
    }

  public:
    int countCompleteSubstrings(string word, int k) {
      int res = 0;

      int i = 0;
      for (int j = 1; j < word.size(); ++j)
        if (abs(word[j] - word[j - 1]) >= 3) {
          res += countCompleteSubstrings(string_view(word.data() + i, j - i), k);

          i = j;
        }

      return res + countCompleteSubstrings(string_view(word.data() + i, word.size() - i), k);
    }
};


int main() {
  EXECS(Solution::countCompleteSubstrings, int, (string, int));
  return 0;
}