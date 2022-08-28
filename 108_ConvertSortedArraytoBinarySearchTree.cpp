#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>


class Solution {
  private:
    TreeNode* divideAndCounqure(int l, int r, const vector<int>& nums) {
      if (l > r) 
        return nullptr;
      
      int m = l + (r-l)/2;
      TreeNode* root = new TreeNode(
        nums[m],
        divideAndCounqure(l, m - 1, nums),
        divideAndCounqure(m + 1, r, nums)
      );

      return root;
    }
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return divideAndCounqure(0, nums.size()-1, nums);
    }
};

int main() {
  EXECS(Solution::sortedArrayToBST);
  return 0;
}
