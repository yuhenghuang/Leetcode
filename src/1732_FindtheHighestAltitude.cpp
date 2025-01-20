#include <local_leetcode.hpp>

class Solution {
  public:
    int largestAltitude(vector<int>& gain) {
      int res = 0;
      
      int sum = 0;
      for (int g : gain)
        if ((sum += g) > res)
          res = sum;

      return res;
    }
};


int main() {
  EXECS(Solution::largestAltitude);
  return 0;
}