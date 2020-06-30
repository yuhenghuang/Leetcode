#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int slow=nums[0], fast=nums[0];
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while (slow!=fast);

      slow = nums[0];
      while (slow!=fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      return fast;
    }

    int findDuplicateWrong(vector<int>& nums) {
      int n=nums.size();
      for (int i=0; i<n; ++i) {
        int idx=i;
        while (idx!=nums[i]-1) {
          idx = nums[i]-1;
          if (nums[idx]==nums[i] && idx!=i) return nums[i];
          swap(i, idx, nums);
        }
      }
      return 0;
    }

    void swap(int& i, int& j, vector<int>& nums) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
};

int main() {
  Solution sol;
  vector<int> nums = {2,1,2};
  cout << sol.findDuplicate(nums) << endl;
  return 0;
}