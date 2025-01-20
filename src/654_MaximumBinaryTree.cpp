#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  private:
    typedef vector<int>::iterator iter_t;

    TreeNode* constructImpl(iter_t begin, iter_t end) {
      if (begin == end)
        return nullptr;

      iter_t iter = max_element(begin, end);

      return new TreeNode(
        *iter,
        constructImpl(begin, iter),
        constructImpl(iter+1, end)
      );
    }

  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return constructImpl(nums.begin(), nums.end());
    }
};


int main() {
  EXECS(Solution::constructMaximumBinaryTree);
  return 0;
}