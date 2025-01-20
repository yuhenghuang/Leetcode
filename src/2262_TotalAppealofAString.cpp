#include <local_leetcode.hpp>

class Solution {
  public:
    long long appealSum(string s) {
      int index[26];
      memset(index, -1, sizeof(index));

      int64_t res = 0;
      int64_t appeal = 0;

      for (int i = 0; i < s.size(); ++i) {
        int& j = index[s[i] - 'a'];

        appeal += i - j;
        res += appeal;

        j = i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::appealSum);
  return 0;
}