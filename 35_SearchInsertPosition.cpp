#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 3, 5, 6};
  cout << sol.searchInsert(nums, 5) << endl;
  cout << sol.searchInsert(nums, 2) << endl;
  cout << sol.searchInsert(nums, 7) << endl;
  cout << sol.searchInsert(nums, 0) << endl;
  return 0;
}