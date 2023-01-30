#include <local_leetcode.hpp>

class Solution {
  private:
    vector<int> init() {
      vector<int> res(38);
      res[1] = res[2] = 1;
      for (int i = 3; i <= 37; ++i)
        res[i] = res[i-1] + res[i-2] + res[i-3];

      return res;
    }

  public:
    int tribonacci(int n) {
      static const vector<int> res = init();

      return res[n];
    }
};


int main() {
  EXECS(Solution::tribonacci);
  return 0;
}