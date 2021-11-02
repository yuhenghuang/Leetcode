#include "utils3.hpp"

class Solution {
public:
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
  UFUNCS(Solution::reverseWords);
  UFUNCS(Solution::reverseWordsRegexIter);
  return 0;
}