#include <local_leetcode.hpp>

class Solution {
  public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
      unordered_map<string_view, int> freq[maxSize - minSize + 1];


      int count[26];
      for (int size = minSize; size <= maxSize; ++size) {
        int i = 0;
        unordered_map<string_view, int>& m = freq[size - minSize];

        int unique = 0;
        memset(count, 0, sizeof(count));
        for (; i < size; ++i)
          if (count[s[i] - 'a']++ == 0)
            ++unique;

        if (unique <= maxLetters)
          ++m[string_view(s.c_str(), size)];

        for (; i < s.size(); ++i) {
          if (count[s[i] - 'a']++ == 0)
            ++unique;

          if (--count[s[i - size] - 'a'] == 0)
            --unique;

        if (unique <= maxLetters)
          ++m[string_view(s.c_str() + (i + 1 - size), size)];
        }
      }

      int res = 0;
      for (unordered_map<string_view, int>& m : freq)
        for (auto& p : m)
          if (p.second > res)
            res = p.second;

      return res;
    }
};


int main() {
  EXECS(Solution::maxFreq);
  return 0;
}