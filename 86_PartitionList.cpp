#include "utils2.hpp"

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode* dummy = new ListNode(INT_MIN, head);

      ListNode* s = dummy;
      while (s->next && s->next->val < x)
        s = s->next;

      ListNode* p, * q;
      p = s->next;
      while (p) {
        while (p->next && p->next->val >= x)
          p = p->next;

        q = p->next;
        if (q) {
          while (q->next && q->next->val < x) 
            q = q->next;

          ListNode* tmp = s->next;

          s->next = p->next;
          p->next = q->next;
          q->next = tmp;

          s = q;
        }
        
        p = p->next;
      }

      return dummy->next;
    }
};


int main() {
  UFUNC(Solution::partition);
  return 0;
}