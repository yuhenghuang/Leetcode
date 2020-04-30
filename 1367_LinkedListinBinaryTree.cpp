#include "DataStructure.h"


class Solution {
  public:
    bool isSubPath(ListNode* head, TreeNode* root) {
      if (!root) return false;
      return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
      if (!head) return true;
      if (!root || root->val != head->val) return false;
      return dfs(head->next, root->left) || dfs( head->next, root->right);
    }
};


class SolutionTLE {
  private:
    bool res;
  public:
    bool isSubPath(ListNode* head, TreeNode* root) {
      res = false;
      dfs(root, head, head);
      return res;
    }

    void dfs(TreeNode* root, ListNode* node, ListNode* head) {
      if (!node) res = true;
      if (res || !root) return;

      if (root->val==node->val) {
        dfs(root->left, node->next, head);
        dfs(root->right, node->next, head);
      }
      dfs(root->left, head, head);
      dfs(root->right, head, head);
    }
};