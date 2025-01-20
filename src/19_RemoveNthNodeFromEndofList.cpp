#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int i) {
      int n = 0;
      ListNode* p = head;
      while (p) {
        p = p->next;
        ++n;
      }

      ListNode dummy(-1, head);
      p = &dummy;
      i = n - i;
      while (i-- > 0) 
        p = p->next;

      ListNode* q = p->next;

      p->next = q->next;
      // delete q;

      return dummy.next;
    }

    ListNode* removeNthFromEnd2Pointers(ListNode* head, int i) {
      ListNode dummy(-1, head);
      ListNode* p = &dummy;
      ListNode* q = &dummy;
      while (i-- > -1) {
        q = q->next;
      }

      while (q) {
        p = p->next;
        q = q->next;
      }

      q = p->next;
      p->next = q->next;
      // delete q;

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::removeNthFromEnd);
  EXECS(Solution::removeNthFromEnd2Pointers);
  return 0;
}
