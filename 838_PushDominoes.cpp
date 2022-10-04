#include <local_leetcode.hpp>

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


    string pushDominoesTwoPointers(string dominoes) {
      int n = dominoes.size();

      string res(n, '.');

      int li = -1; // left index
      char ld = 'L'; // left direction

      while (li < n) {
        int ri = li + 1; // right index
        
        while (ri < n && dominoes[ri] == '.')
          ++ri;

        char rd = ri < n ? dominoes[ri] : 'R'; // right direction

        if (ri < n)
          res[ri] = rd;
      
        if (ld == 'L') {
          if (rd == 'L')
            for (int i = ri - 1; i > li; --i)
              res[i] = 'L';
        }
        else {
          if (rd == 'R')
            for (int i = li + 1; i < ri; ++i)
              res[i] = 'R';
          else
            for (int i = li + 1, j = ri - 1; i < j; ++i, --j) {
              res[i] = 'R';
              res[j] = 'L';
            }
        }

        li = ri;
        ld = rd;
      }

      return res;
    }

};


int main() {
  EXECS(Solution::pushDominoes);
  EXECS(Solution::pushDominoesTwoPointers);
  return 0;
}
