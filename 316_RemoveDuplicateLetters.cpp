#include "utils.hpp"

using namespace std;

class Solution {
  public:
    string removeDuplicateLetters(string s) {
      int n = s.size();
      bool seen[26] = {0};
      int idx[26] = {0};

      for (int i=0; i<n; ++i)
        idx[s[i]-'a'] = i;

      string res;
      for (int i=0; i<n; ++i) {
        int b = s[i] - 'a';
        if (seen[b]) continue; // it is always to pick a letter in the front

        // if a letter can be found in following loops, it shall leave position to smaller letter
        while (!s.empty() && s[i] < res.back() && i<idx[res.back()-'a']) {
          seen[res.back()-'a'] = false;
          res.pop_back();
        }

        seen[b] = true;
        res.push_back(s[i]);
      }

      return res;
    }

    string removeDuplicateLettersBits(string s) {
      int n=s.size();
      vector<int> memo(n);

      int mask=0;
      for (int i=n-2; i>=0; --i) {
        memo[i] = memo[i+1] | 1 << (s[i+1]-'a');
      }

      mask = memo[0] | (1 << (s.front()-'a'));

      int st=0;
      string res;
      while (mask>0) {

        int j;
        bool flag;
        for (int i=0; i<26; ++i) {
          if (((mask >> i) & 1)==0) continue;

          int rem = mask ^ (1 << i);
          char c = 'a' + i;
          flag = false;
          for (j=st; j<n; ++j) {
            if (s[j]==c && (memo[j] | rem)==memo[j]) {
              flag = true;
              break;
            }
          }

          if (flag) {
            res.push_back(c);
            mask = rem;
            st = j+1;
            break;
          }
        }
      }

      return res;
    }
};


int main() {
  Solution sol;

  ifstream f("Inputs/316_RemoveDuplicateLetters.txt");
  string s, res;
  while (getline(f, s)) {
    res = sol.removeDuplicateLetters(s);
    cout << res << " " << sol.removeDuplicateLettersBits(s) << endl;
  }

  return 0;
}