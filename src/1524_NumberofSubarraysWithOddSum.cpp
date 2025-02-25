#include <local_leetcode.hpp>

class Solution {
  public:
    int numOfSubarrays(vector<int>& arr) {
      constexpr int mod = 1e9 + 7;

      int res = 0;

      pair<int, int> p;
      for (int num : arr) {
        // odd
        if (num & 1) {
          swap(p.first, p.second);
          ++p.first;
        }
        else 
          ++p.second;

        res += p.first;

        if (res > mod) [[ unlikely ]]
          res -= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numOfSubarrays);
  return 0;
}