#include "utils2.hpp"

class Solution {
  private:
    bool match(const string& s, const string& p) {
      int n = s.size();
      if (n == p.size()) {
        int word2pat[26], pat2word[26];
        memset(word2pat, -1, 26 * sizeof(int));
        memset(pat2word, -1, 26 * sizeof(int));

        for (int i = 0; i < n; ++i) {
          int si = s[i] - 'a';
          int pi = p[i] - 'a';
          if (word2pat[si] ==  -1 && pat2word[pi] == -1) {
            word2pat[si] = pi;
            pat2word[pi] = si;
          }
          else if (word2pat[si] != pi || pat2word[pi] != si) 
            return false;
        }

        return true;
      }

      return false;
    }
  public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
      vector<string> res;

      for (const string& w : words)
        if (match(w, pattern))
          res.push_back(w);

      return res;
    }
};


int main() {
  UFUNC(Solution::findAndReplacePattern);
  return 0;
}