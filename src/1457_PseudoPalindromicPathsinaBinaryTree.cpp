#include <local_leetcode.hpp>

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

    int pseudoPalindromicPathsNew(TreeNode* root) {
      int res = 0;

      // tree node, bits
      queue<pair<TreeNode*, int>> q;

      if (root)
        q.emplace(root, 0);

      while (!q.empty()) {
        auto [node, bits] = q.front();
        q.pop();

        bits ^= 1 << (node->val - 1);

        // leaf node
        if (!node->left and !node->right) {
          // at most one odd count of digits
          if (__builtin_popcount(bits) < 2)
            ++res;
        }
        // non-leaf node
        else {
          if (node->left)
            q.emplace(node->left, bits);
          if (node->right)
            q.emplace(node->right, bits);
        }
      }

      return res;
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
  EXECS(Solution::pseudoPalindromicPaths);
  EXECS(Solution::pseudoPalindromicPathsNew);
  return 0;
}