#include <local_leetcode.hpp>

class Solution {
  public:
    int countCharacters(vector<string>& words, string chars) {
      int freq[26] = {0};
      for (char c : chars)
        ++freq[c - 'a'];

      int res = 0;

      int curr[26];
      for (const string& w : words) {
        memcpy(curr, freq, sizeof(int) * 26);

        bool flag = true;
        for (char c : w)
          if (--curr[c - 'a'] < 0) {
            flag = false;
            break;
          }

        if (flag)
          res += w.size();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countCharacters);
  return 0;
}