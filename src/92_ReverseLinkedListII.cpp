#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (left == right)
        return head;

      ListNode dummy(-1, head);

      // left node of left boundary
      ListNode* ll = &dummy;
      int i = 0;
      for (; i < left - 1; ++i)
        ll = ll->next;

      // left boundary
      ListNode* l = ll->next;

      // right boundary
      ListNode* r = l;
      // right node of right boundary
      ListNode* rr = r->next;
      for (++i; i < right; ++i) {
        ListNode* tmp = rr->next;
        rr->next = r;
        
        r = rr;
        rr = tmp;
      }

      ll->next = r;
      l->next = rr;

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::reverseBetween);
  return 0;
}