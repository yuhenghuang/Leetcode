#include "utils3.hpp"

class Solution {
  private:
    ListNode* reverseOneGroup(ListNode* ll, int k) {
      // ll, l, ..., r, rr
      // reverse inclusively between l and r

      ListNode* rr = ll->next;
      while (k-- && rr) 
        rr = rr->next;

      if (k != -1)
        return nullptr;

      ListNode* l = ll->next;

      // ListNode* r is p;
      ListNode* p = l;
      ListNode* q = p->next;
      while (q != rr) {
        ListNode* tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
      }

      ll->next = p;
      l->next = rr;

      return l;
    }

  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k == 1)
        return head;

      ListNode dummy(-1, head);

      ListNode* p = &dummy;
      while (p)
        p = reverseOneGroup(p, k);

      return dummy.next;
    }

    ListNode* reverseKGroupRecursive(ListNode* head, int k) {
      // if (k == 1) return head;

      ListNode* rr = head;
      for (int i = 0; i < k; ++i) {
        if (rr == nullptr)
          return head;
        
        rr = rr->next;
      }

      ListNode* p = head;
      ListNode* q = p->next;
      while (q != rr) {
        ListNode* tmp = q->next;
        q->next = p;

        p = q;
        q = tmp;
      }

      head->next = reverseKGroupRecursive(rr, k);
      return p;
    }
};


int main() {
  UFUNCS(Solution::reverseKGroup);
  UFUNCS(Solution::reverseKGroupRecursive);
  return 0;
}