#include <local_leetcode.hpp>

class Solution {
  public:
    int arraySign(vector<int>& nums) {
      int res = 1;
      
      for (int num : nums) {
        if (num < 0)
          res = -res;
        else if (num == 0)
          return 0;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::arraySign);
  return 0;
}