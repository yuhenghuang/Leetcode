#include <string>
#include <iostream>
using namespace std;

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
};

int main() {
  Solution sol;
  cout << sol.reverseWords(" ") << endl;
  return 0;
}