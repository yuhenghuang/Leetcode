#include "utils3.hpp"

class Solution {
  public:
    int countSpecialSubsequences(vector<int>& nums) {
      constexpr int mod = 1e9 + 7;

      int res = 0;
      int zero, one, two;
      zero = one = two = 0;
      for (int num : nums) {
        if (num == 0) 
          zero = ((zero << 1) + 1) % mod;
        else if (num == 1) {
          // add subseqs end with num
          one = (one << 1) % mod;
          one = (zero + one) % mod;
        }
        else {
          // subseqs end with num
          int temp = (one + two) % mod;
          res = (res + temp) % mod;

          // add prior subseqs
          two = (temp + two) % mod;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::countSpecialSubsequences);
  return 0;
}