#include "utils.hpp"

class Solution {
  public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      auto i1 = word1.begin(), i2 = word2.begin();
      string::iterator j1 = (*i1).begin(), j2 = (*i2).begin();
      while (i1!=word1.end() && i2!=word2.end()) {
        if (*j1++!=*j2++)
          return false;

        if (j1==(*i1).end()) {
          ++i1;
          j1 = (*i1).begin();
        }

        if (j2==(*i2).end()) {
          ++i2;
          j2 = (*i2).begin();
        }
      }

      return i1==word1.end() && i2==word2.end();
    }
};


int main() {
  UFUNC(Solution::arrayStringsAreEqual);
  return 0;
}