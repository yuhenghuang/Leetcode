#include "utils3.hpp"

class Solution {
  public:
    int minDeletions(string s) {
      int count[27] = {0};
      count[26] = INT_MAX;
      for (char c : s)
        ++count[c - 'a'];

      sort(begin(count), end(count), greater<int>());

      int res = 0;
      for (int i = 1; i <= 26; ++i) {
        if (count[i] == 0)
          break;
        else if (count[i-1] > count[i])
          continue;
        else if (count[i-1] == 0){
          res += count[i] - count[i-1];
          count[i] = 0;
        }
        else {
          res += count[i] - count[i-1] + 1;
          count[i] = count[i-1] - 1;
        }

      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::minDeletions);
  return 0;
}