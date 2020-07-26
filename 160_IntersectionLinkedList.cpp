#include "DataStructure.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *p = headA, *q = headB;
      while (p!=q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
      }
      return p;
    }
};