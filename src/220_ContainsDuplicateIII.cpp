#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      multiset<long> s;
      size_t n = nums.size();

      long diff = LONG_MAX, num;
      for (size_t i=0; i<n; ++i) {
        num = nums[i];
        if (i>k)
          s.erase(s.lower_bound(nums[i-k-1]));
        
        auto iter = s.insert(nums[i]);

        if (iter!=s.begin()) {
          diff = min(diff, abs(*(--iter) - num));
          ++iter;
        }
        if (++iter!=s.end())
          diff = min(diff, abs(*(iter) - num));

        if (diff<=t)
          return true;
      }

      return false;
    }
};

int main() {
  Solution sol;
  // vector<int> nums = {1, 2, 3, 1};
  // vector<int> nums = {1, 0, 1, 1};
  // vector<int> nums = {1,5,9,1,5,9};
  vector<int> nums = {-1, 2147483647};
  cout << sol.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;
  return 0;
}