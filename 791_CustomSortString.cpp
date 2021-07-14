#include "utils3.hpp"

class Solution {
  public:
    string customSortString(string order, string str) {
      vector<int> rank(26);
      for (int i = 0; i < order.size(); ++i) {
        rank[order[i] - 'a'] = i;
      }

      sort(str.begin(), str.end(),
        [&rank](char i, char j) -> bool {
          return rank[i - 'a'] < rank[j - 'a'];
        }
      );

      return str;
    }

    string customSortStringBucket(string order, string str) {
      int count[26];
      memset(count, 0, sizeof(count));

      for (char c : str)
        ++count[c - 'a'];

      string res;
      for (char c : order) {
        res += string(count[c - 'a'], c);
        count[c - 'a'] = 0;
      }

      for (int i = 0; i < 26; ++i)
        if (count[i] > 0)
          res += string(count[i], 'a' + i);

      return res;
    }
};


int main() {
  UFUNCS(Solution::customSortString);
  UFUNCS(Solution::customSortStringBucket);
  return 0;
}