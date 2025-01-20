#include "utils3.hpp"

class Solution {
  public:
    int chalkReplacer(vector<int>& chalk, int k) {
      int n = chalk.size();

      vector<int> prefix;
      prefix.reserve(n);

      prefix.push_back(0);
      for (int i = 0; i < n; ++i) {
        if (prefix.back() > k)
          break;

        prefix.push_back(prefix.back() + chalk[i]);
      }

      k = k % prefix.back();

      return upper_bound(prefix.begin() + 1, prefix.end(), k) - prefix.begin() - 1;
    }
};


int main() {
  UFUNCS(Solution::chalkReplacer);
  return 0;
}