#include <local_leetcode.hpp>

class Solution {
  public:
    string predictPartyVictory(string senate) {
      int n = senate.size();

      int cr = count(senate.begin(), senate.end(), 'R');
      int cd = n - cr;

      for (int i = 0, r = 0, d = 0; cr > 0 & cd > 0; i = (i + 1) % n) {
        if (senate[i] == 'R') {
          for (;senate[r] != 'D'; r = (r + 1) % n);

          senate[r] = '*';
          --cd;
        }
        else if (senate[i] == 'D') {
          for (;senate[d] != 'R'; d = (d + 1) % n);

          senate[d] = '*';
          --cr;
        }

        if (i == r)
          r = (r + 1) % n;
        
        if (i == d)
          d = (d + 1) % n;
      }

      return cr > 0 ? "Radiant" : "Dire";
    }
};


int main() {
  EXECS(Solution::predictPartyVictory);
  return 0;
}