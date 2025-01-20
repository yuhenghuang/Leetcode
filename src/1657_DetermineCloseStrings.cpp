#include "utils.hpp"

class Solution {
  public:
    bool closeStrings(string word1, string word2) {
      int n = word1.size();
      if (n!=word2.size())
        return false;

      vector<int> cnt1(26), cnt2(26);
      for (int i=0; i<n; ++i) {
        ++cnt1[word1[i]-'a'];
        ++cnt2[word2[i]-'a'];
      }

      for (int i=0; i<26; ++i) {
        if (cnt1[i]==cnt2[i])
          continue;

        if (cnt1[i]==0 || cnt2[i]==0)
          return false;

        for (int j=i+1; j<26; ++j)
          if (cnt1[i] == cnt2[j]) {
            swap(cnt2[i], cnt2[j]);
            break;
          }

        if (cnt1[i]!=cnt2[i])
          return false;
      }

      return true;
    }
};


int main() {
  UFUNC(Solution::closeStrings);
  return 0;
}