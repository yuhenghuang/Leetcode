#include <local_leetcode.hpp>

class Solution {
  public:
    void deleteNode(ListNode* node) {
      *node = *(node->next);
    }

    ListNode* deleteNode(ListNode* head, int node) {
      deleteNode(
        ll::find_node(head, node)
      );
      return head;
    }
};


int main() {
  EXECS(Solution::deleteNode, ListNode*, (ListNode*, int));
  return 0;
}