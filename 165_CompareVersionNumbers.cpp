#include <string>
#include <iostream>

using namespace std;

class Solution {
  private:
    int next_num(string &ver, size_t &st) {
      size_t ed=ver.find('.', st);
      if (ed==string::npos)
        ed = ver.length();

      int res = stoi(ver.substr(st, ed-st));
      st = ed+1;
      return res;
    }
  public:
    int compareVersion(string version1, string version2) {
      size_t m=version1.size(), n=version2.size();

      int num1, num2;
      size_t st1=0, st2=0;
      while (st1<m || st2<n) {
        num1 = st1<m ? next_num(version1, st1) : 0;
        num2 = st2<n ? next_num(version2, st2) : 0;

        if (num1>num2)
          return 1;
        else if (num1<num2)
          return -1;
      }

      return 0;
    }
};

int main() {
  Solution sol;
  cout << sol.compareVersion("7.5.2.4", "7.5.3") << endl;
  cout << sol.compareVersion("1.01", "1.001") << endl;
  cout << sol.compareVersion("1.0.1", "1") << endl;
  return 0;
}