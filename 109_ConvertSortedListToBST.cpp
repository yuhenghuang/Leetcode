#include "utils2.hpp"

class Solution {
  private:
    TreeNode* dfs(const vector<TreeNode*>& nodes, int i, int j) {
      if (i > j)
        return nullptr;
      else if (i == j)
        return nodes[i];

      int m = i + (j-i) / 2;
      nodes[m]->left = dfs(nodes, i, m-1);
      nodes[m]->right = dfs(nodes, m+1, j);

      return nodes[m];
    }

  public:
    TreeNode* sortedListToBST(ListNode* head) {
      vector<TreeNode*> nodes;

      while (head) {
        nodes.push_back(new TreeNode(head->val));
        head = head->next;
      }

      return dfs(nodes, 0, nodes.size() - 1);
    }
};


int main() {
  UFUNC(Solution::sortedListToBST);
  return 0;
}