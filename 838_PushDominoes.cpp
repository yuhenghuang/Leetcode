#include "utils3.hpp"

class Solution {
  public:
    string pushDominoes(string dominoes) {
      int n = dominoes.size();

      int m = 0;
      int a = 0;
      vector<int> momentum(n);
      for (int i = 0; i < n; ++i) {
        m += a;

        if (dominoes[i] == 'R') {
          m = n;
          a = -1;
        }
        else if (dominoes[i] == 'L') {
          m = 0;
          a = 0;
        }

        momentum[i] = m;
      }

      m = 0;
      a = 0;
      for (int i = n - 1; i >= 0; --i) {
        m += a;
        if (dominoes[i] == 'L') {
          m = -n;
          a = 1;
        }
        else if (dominoes[i] == 'R') {
          m = 0;
          a = 0;
        }

        momentum[i] += m;
      }

      string res;
      for (int m : momentum) {
        if (m > 0)
          res.push_back('R');
        else if (m < 0)
          res.push_back('L');
        else
          res.push_back('.');
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::pushDominoes);
  return 0;
}