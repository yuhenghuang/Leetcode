#include "DataStructure.h"
using namespace std;

class Solution {
  private:
    TreeNode* res;
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root, p ,q);
      return res;
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
      int count=0;
      if (root==nullptr) return count;
      if (root==p || root==q) count++;
      count+=dfs(root->left, p, q);
      count+=dfs(root->right, p, q);

      if (count>1 && res==nullptr)
        res = root;
      return count;
    }
};