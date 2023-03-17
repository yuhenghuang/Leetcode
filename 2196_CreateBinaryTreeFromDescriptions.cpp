#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      // val, node
      unordered_map<int, TreeNode*> m;

      for (auto& desc : descriptions)
        m[desc[1]] = new TreeNode(desc[1]);

      TreeNode* root;
      for (auto& desc : descriptions) {
        TreeNode* TreeNode::*child = desc[2] ? &TreeNode::left : &TreeNode::right;

        auto iter = m.find(desc[0]);

        if (iter != m.end()) [[likely]]
          iter->second->*child = m[desc[1]];
        else {
          root = m[desc[0]] = new TreeNode(desc[0]);
          root->*child = m[desc[1]];
        }
      }

      return root;
    }
};


int main() {
  EXECS(Solution::createBinaryTree);
  return 0;
}