#include <local_leetcode.hpp>

class Solution {
  public:
    bool wordPattern(string pattern, string s) {
      string_view idx2str[26];
      unordered_map<string_view, int> str2idx;

      size_t i = 0;

      size_t k = 0;
      while (k < pattern.size() && i < s.size()) {
        int idx = pattern[k++] - 'a';

        size_t j = s.find_first_of(' ', i);

        if (j == string::npos)
          j = s.size();

        string_view tmp(s.c_str() + i, j - i);
        if (idx2str[idx].empty() && str2idx.find(tmp) == str2idx.end()) {
          idx2str[idx] = tmp;
          str2idx[tmp] = idx;
        }
        else if (idx2str[idx] != tmp || str2idx[tmp] != idx)
          return false;

        i = j + 1;
      }

      return k == pattern.size() && i == s.size() + 1UL;
    }
};


int main() {
  EXECS(Solution::wordPattern);
  return 0;
}