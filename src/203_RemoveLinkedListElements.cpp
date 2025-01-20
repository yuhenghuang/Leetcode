#include "utils3.hpp"

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode dummy(0, head);
      ListNode* p = &dummy;
      ListNode* q;
      while (p) {
        q = p->next;
        if (q && q->val==val) {
          p->next = q->next;
          // p = q->next;
          // original linked list is allocated by new[]
          // no need to worry about memory leak
          // delete q;
        }
        else 
          p = q;
      }
      return dummy.next;
    }
};

int main() {
  UFUNCS(Solution::removeElements);
  return 0;
}