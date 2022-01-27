#include <local_leetcode.hpp>

class Solution {
  public:
    bool hasCycle(ListNode *head) {
      ListNode* p = head;
      ListNode* q = head;

      if (p) {
        p = p->next;
        q = q->next;
      }

      if (q)
        q = q->next;

      while (p != q) {
        if (p) p = p->next;

        if (q) q = q->next;
        if (q) q = q->next;
      }

      return p;
    }

  bool hasCycle(ListNode* head, int pos) {
    return hasCycle(
      ll::create_cycle(head, pos)
    );
  }
};


int main() {
  EXECS(Solution::hasCycle, bool, (ListNode*, int));
  return 0;
}