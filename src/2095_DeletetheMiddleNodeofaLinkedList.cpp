#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* deleteMiddle(ListNode* head) {
      ListNode dummy(0, head);

      ListNode* p = &dummy;
      ListNode* q = head->next;

      while (q) {
        q = q->next;
        if (q)
          q = q->next;
        
        p = p->next;
      }

      p->next = p->next->next;

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::deleteMiddle);
  return 0;
}