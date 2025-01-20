#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode dummy(INT_MIN, head);

      ListNode* s = &dummy;
      while (s->next && s->next->val < x)
        s = s->next;

      ListNode* p;
      ListNode* q;

      p = s->next;
      while (p) {
        while (p->next && p->next->val >= x)
          p = p->next;

        // p->val >= x and q->val < x
        q = p->next;
        if (q) {
          while (q->next && q->next->val < x) 
            q = q->next;

          ListNode* tmp = s->next;

          s->next = p->next;
          p->next = q->next; // skip [p+1, q] where val < x
          q->next = tmp;

          s = q;
        }
        
        p = p->next;
      }

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::partition);
  return 0;
}
