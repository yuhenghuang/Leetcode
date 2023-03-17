#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>


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

    TreeNode* dfs(ListNode* head, ListNode* tail) {
      if (head == tail)
        return nullptr;

      ListNode* p = head;
      ListNode* q = head;

      while (q != tail) {
        q = q->next;
        if (q != tail) {
          q = q->next;
          p = p->next;
        }
      }

      return new TreeNode(
        p->val,
        dfs(head, p),
        dfs(p->next, tail)
      );
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

    TreeNode* sortedListToBSTO1(ListNode* head) {
      // no extra memory except call stack
      return dfs(head, nullptr);
    }
};


int main() {
  EXECS(Solution::sortedListToBST);
  EXECS(Solution::sortedListToBSTO1);
  return 0;
}