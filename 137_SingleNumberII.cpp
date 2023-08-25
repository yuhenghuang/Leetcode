#include <local_leetcode.hpp>

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      // simulate 3-base number system

      int low = 0, high = 0;

      // 0: low = 0, high = 0;
      // 1: low = 1, high = 0;
      // 2: low = 1, high = 1;
      for (int num : nums) {
        high ^= num & low; // add bit to high if current low is 1
        low ^= num & (~high); // add bit to low if next high is 0
      }

      return low;
    }
};


int main() {
  EXECS(Solution::singleNumber);
  return 0;
}