#include "utils.hpp"

class Solution {
  private:
    static bool pow2[512];
    friend int init();

    int dfs(TreeNode* root, int b) {
      if (!root)
        return 0;
      
      b ^= 1 << (root->val - 1);
      if (!root->left && !root->right)
        // return b==0 || pow2[b];
        return (b & (b-1))==0;

      return dfs(root->left, b) + dfs(root->right, b);
    }

  public:
    int pseudoPalindromicPaths(TreeNode* root) {
      return dfs(root, 0);
    }
};

bool Solution::pow2[] = {0};

int init() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i=0; i<9; ++i)
    Solution::pow2[(1<<i)] = true;

  return 0;
}

static const int emm = init();


int main() {
  UFUNC(Solution::pseudoPalindromicPaths);
  return 0;
}