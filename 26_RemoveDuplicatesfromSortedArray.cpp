#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size()==0) return 0;
      int p=0;
      for (int q=1; q<nums.size(); q++) 
        if (nums[p]!=nums[q]) {
          nums[++p] = nums[q];
        }
      return p+1;
    }
};