#include <local_leetcode.hpp>

class Solution {
  private:
    int cumsum;
    void dfs(TreeNode* root) {
      if (!root)
        return;

      dfs(root->right);

      cumsum += root->val;
      root->val = cumsum;

      dfs(root->left);
    }


    TreeNode* getNext(TreeNode* root) {
      TreeNode* nx = root->right;
      while (nx->left && nx->left != root)
        nx = nx->left;
      return nx;
    }

  public:
    TreeNode* convertBSTRecur(TreeNode* root) {
      cumsum = 0;
      dfs(root);

      return root;
    }


    TreeNode* convertBST(TreeNode* root) {
      int sum = 0;
      TreeNode* node = root;

      while (node) {
        if (!node->right) {
          sum += node->val;
          node->val = sum;
          node = node->left;
        }
        else {
          TreeNode* nx = getNext(node);

          // nx is the leftmost node of node->right before connection
          if (!nx->left) {
            nx->left = node;
            node = node->right;
          }
          // release connection
          else {
            nx->left = nullptr;
            sum += node->val;
            node->val = sum;
            node = node->left;
          }
        }
      }

      return root;
    }
};


int main() {
  EXECS(Solution::convertBST);
  EXECS(Solution::convertBSTRecur);
  return 0;
}