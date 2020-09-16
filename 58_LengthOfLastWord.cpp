#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
      auto ed = s.rbegin();
      while (ed!=s.rend() && *ed==' ')
        ++ed;

      auto st = ed;
      while (st!=s.rend() && *st!=' ')
        ++st;

      return st - ed;
    }
};

int main() {
  Solution sol;
  string s;
  // eof triggered by ctrl+d on linux or ctrl+z on windows
  while (getline(cin, s)) {
    // if (s.size()==0) break;
    cout << sol.lengthOfLastWord(s) << endl;
  }
  return 0;
}