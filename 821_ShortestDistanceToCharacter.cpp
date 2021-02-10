#include "utils2.hpp"

class Solution {
  public:
    vector<int> shortestToChar(string s, char c) {
      int n = s.size();
      vector<int> res(n);

      int ci = INT_MIN + n;
      for (int i=0; i<n; ++i) {
        if (s[i]==c) 
          ci = i;

        res[i] = i - ci;
      }

      ci = INT_MAX;
      for (int i=n-1; i>=0; --i) {
        if (s[i]==c) 
          ci = i;

        res[i] = min(res[i], ci - i);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::shortestToChar);
  return 0;
}