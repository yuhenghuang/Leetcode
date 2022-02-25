#include <local_leetcode.hpp>

class Solution {
  public:
    bool canArrange(vector<int>& arr, int k) {
      vector<int> remainders(k);

      for (int num : arr) {
        num %= k;

        if (num < 0)
          num += k;

        ++remainders[num];
      }

      if ((remainders[0] & 1) || (k % 2 == 0 && (remainders[k / 2] & 1)))
        return false;

      for (int i = 1; i < (k + 1) / 2; ++i)
        if (remainders[i] != remainders[k - i])
          return false;


      return true;
    }
};


int main() {
  EXECS(Solution::canArrange);
  return 0;
}