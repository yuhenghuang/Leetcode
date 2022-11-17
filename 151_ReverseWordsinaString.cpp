#include <local_leetcode.hpp>

class Solution {
  public:
    string reverseWordsO1(string s) {
      // O(1) space

      typedef string::iterator iter_t;

      reverse(s.begin(), s.end());

      iter_t i = s.begin(); // begin of writing word
      iter_t k = s.begin(); // end of reading (last) word
      while (i != s.end()) {
        if (i != s.begin())
          *i++ = ' ';

        iter_t j = k; // begin of reading word
        while (j != s.end() && *j == ' ') ++j;

        // no next word
        if (j == s.end())
          break;

        k = j;
        while (k != s.end() && *k != ' ') ++k;

        reverse(j, k);
        i = copy(j, k, i);
      }

      // remove trailing spaces.
      // for (; i != s.end(); ++i) *i = ' ';
      s.resize(i - s.begin());

      while (s.back() == ' ')
        s.pop_back();

      return s;
    }

    string reverseWords(string s) {
      int r = s.size()-1;
      if (r<0) return s;
      int m, l;
      while (r>-1) {
        m = r;
        while (m>=0 && s[m]==' ')
          --m;
        l = m;
        while (l>=0 && s[l]!=' ')
          --l;
        for (int i=l+1; i<=m; ++i)
          s.push_back(s[i]);
        if (m>l)
          s.push_back(' ');
        s.erase(l+1, r-l);
        r = l;
      }
      if (s.size()>0)
        s.pop_back();
      return s;
    }

    string reverseWordsRegexIter(string s) {
      regex re("\\w+");
      regex_iterator iter(s.rbegin(), s.rend(), re);
      regex_iterator<string::reverse_iterator> end;

      string res;
      while (iter != end) {
        string&& temp = iter++->str();
        reverse(temp.begin(), temp.end());
        res.append(temp);

        res.push_back(' ');
      }

      if (!res.empty())
        res.pop_back();

      return res;
    }
};

int main() {
  EXECS(Solution::reverseWords);
  EXECS(Solution::reverseWordsRegexIter);
  EXECS(Solution::reverseWordsO1);
  return 0;
}
