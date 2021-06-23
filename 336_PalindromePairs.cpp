#include "utils2.hpp"

class Solution {
  private:
    bool isPalindromic(int i, int j, const string& s) {
      while (i < j) {
        if (s[i++] != s[j--])
          return false;
      }

      return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
      int n = words.size();

      // save the index of REVERSED words
      unordered_map<string, int> word2idx;
      for (int i = 0; i < n; ++i) {
        const string& w = words[i];
        string s(w.rbegin(), w.rend());
        word2idx[s] = i;
      }


      unordered_map<string, int>::iterator iter;
      vector<vector<int>> res;
      for (int i = 0; i < n; ++i) {
        const string& w = words[i];

        // find the palindromic overlapped substring,
        // and look up the reversed non-overlapped substring
        for (int j = 0; j <= w.size(); ++j) {
          // words[i] on left
          if (isPalindromic(j, w.size() - 1, w)) {
            iter = word2idx.find(w.substr(0, j));

            // avoid the case where words[i] + words[i] is palindrome
            if (iter != word2idx.end() && iter->second != i)
              res.push_back({i, iter->second});
          }

          // words[i] on right
          // j > 0 to avoid duplicate caused by symmetric cases, e.g. abc + cba
          if (j > 0 && isPalindromic(0, j - 1, w)) {
            iter = word2idx.find(w.substr(j, w.size() - j));

            if (iter != word2idx.end())
              res.push_back({iter->second, i});
          }
        }
      }

      return res;
    }
};

int main() {
  {
    UFUNC(Solution::palindromePairs);
  }
  return 0;
}