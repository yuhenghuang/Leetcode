#include <local_leetcode.hpp>

class Solution {
  public:
    string kthLargestNumber(vector<string>& nums, int k) {
      sort(
        nums.begin(),
        nums.end(),
        [](const string& x, const string& y) {
          if (x.size() == y.size()) 
            return x > y;
          else
            return x.size() > y.size();
        }
      );

      return nums[k - 1];
    }
};


int main() {
  EXECS(Solution::kthLargestNumber);
  return 0;
}