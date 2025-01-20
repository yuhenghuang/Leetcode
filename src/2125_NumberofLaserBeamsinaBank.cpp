#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfBeams(vector<string>& bank) {
      int res = 0;

      for (int i = 0, d = 0; i < bank.size(); ++i) {
        int tmp = count(bank[i].begin(), bank[i].end(), '1');

        if (tmp > 0) {
          res += d * tmp;
          d = tmp;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numberOfBeams);
  return 0;
}