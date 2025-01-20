#include "utils.hpp"

using namespace std;

class Solution {
  public:
    bool buddyStrings(string A, string B) {
      if (A.size()!=B.size() || A.size()<2)
        return false;

      int n = A.size();
      string a, b;
      for (int i=0; i<n; ++i)
        if (A[i]!=B[i]) {
          a.push_back(A[i]);
          b.push_back(B[i]);
        }

      if (a.size()==0 && b.size()==0) {
        int count[26] = {0};
        for (char c : A) {
          ++count[c-'a'];
          if (count[c-'a']>1)
            return true;
        }
      }
      else if (a.size()==2 && b.size()==2) {
        return a[0]==b[1] && a[1]==b[0];
      }

      return false;
    }
};


int main() {
  Solution sol;

  vector<string> args;

  ifstream f("Inputs/859_BuddyStrings.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    
    cout << sol.buddyStrings(args[0], args[1]) << endl;
  }

  return 0;
}