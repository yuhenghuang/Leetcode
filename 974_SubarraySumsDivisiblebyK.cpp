#include <local_leetcode.hpp>

class Solution {
  public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int res = 0;

      int sum = 0;
      // prefix sum % k, count
      unordered_map<int, int> m;
      ++m[0]; 

      for (const int& num : nums) {
        sum += num;

        // handle negative sum
        int rem = (sum % k + k) % k;

        res += m[rem];

        ++m[rem];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::subarraysDivByK);
  return 0;
}