#include "utils.hpp"

using namespace std;

class Solution {
  private:
    int l, r;
    TreeNode *t1, *t2;

    void dfs_l(TreeNode* root, int& n1) {
      if (!root) return;
      r = root->val;
      dfs_l(root->left, n1);

      if (root->val < l) {
        n1 = root->val;
        t1 = root;
      }

      l = root->val;
      dfs_l(root->right, n1);
    }

    void dfs_r(TreeNode* root, int& n2) {
      if (!root) return;
      l = root->val;
      dfs_r(root->right, n2);

      if (root->val > r) {
        n2 = root->val;
        t2 = root;
      }

      r = root->val;
      dfs_r(root->left, n2);
    }

    void swap_node(TreeNode* root, const int& n1, const int& n2) {
      if (!root) return;

      if (root->val == n1) {
        root->val = n2;
      }
      else if (root->val == n2) {
        root->val = n1;
      }

      swap_node(root->left, n1, n2);
      swap_node(root->right, n1, n2);
    }

  public:
    void recoverTree(TreeNode* root) {

      int n1, n2;

      l = INT_MIN;
      dfs_l(root, n1);

      r = INT_MAX;
      dfs_r(root, n2);

      // swap_node(root, n1, n2);
      swap(t1->val, t2->val);
    }
};


int main() {
  UFUNC(Solution::recoverTree);
  return 0;
}