#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> res;
      res.reserve(num + 1);
      res.push_back(0);

      for (int i = 1; i <= num;) {
        int n = res.size();
        for (int j = 0; j < n && i <= num; ++i, ++j)
          res.push_back(res[j] + 1);
      }

      return res;
    }

    vector<int> countBitsOld(int num) {
      vector<int> res(num+1);
      res[0] = 0;
      int jump = 1, temp = jump;
      for (int i=1; i<=num; ++i) {
        if (temp==0) {
          jump <<= 1;
          temp = jump;
        }
        res[i] = 1 + res[i-jump];
        --temp;
      }
      return res;
    }
};


int main() {
  EXECS(Solution::countBits);
  EXECS(Solution::countBitsOld);
  return 0;
}