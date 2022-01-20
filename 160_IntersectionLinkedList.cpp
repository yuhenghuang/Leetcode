#include <local_leetcode.hpp>

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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB, int skipA, int skipB) {
      if (skipA == 0 && skipB == 0)
        return getIntersectionNode(headA, headA);

      ll::intersect_linked_lists(headA, headB, skipA, skipB);
      return getIntersectionNode(headA, headB);
    }
};


int main() {
  EXECS(Solution::getIntersectionNode, ListNode*, (ListNode*, ListNode*, int, int));
  return 0;
}