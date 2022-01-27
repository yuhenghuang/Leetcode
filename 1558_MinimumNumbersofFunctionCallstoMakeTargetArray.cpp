#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(vector<int>& nums) {
      // count of 1's in each bit
      vector<int> count(31);

      for (int num : nums) {

        int* iter = count.data();
        while (num > 0) {
          if (num & 1)
            ++(*iter);

          ++iter;
          num >>= 1;
        }
      }

      while (!count.empty() && count.back() == 0)
        count.pop_back();

      int res = accumulate(count.begin(), count.end(), 0);

      return count.empty() ? 0 : res + (int)count.size() - 1;
    }
};


int main() {
  EXECS(Solution::minOperations);
  return 0;
}