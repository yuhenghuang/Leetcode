#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode dummy(INT_MIN);

      ListNode* p = &dummy;
      while (l1 && l2) {
        if (l1->val < l2->val) {
          p->next = l1;
          l1 = l1->next;
        }
        else {
          p->next = l2;
          l2 = l2->next;
        }

        p = p->next;
      }

      // remaining nodes in l1 or l2
      p->next = l1 ? l1 : l2;

      return dummy.next;
    }

    ListNode* mergeTwoListsDFS(ListNode* l1, ListNode* l2) {
      if (l1 && l2) {
        // only for simplicity
        if (l1->val > l2->val)
          swap(l1, l2);

        l1->next = mergeTwoLists(l1->next, l2);
      }
      
      return l1 ? l1 : l2;
    }
};


int main() {
  EXECS(Solution::mergeTwoLists);
  EXECS(Solution::mergeTwoListsDFS);
  return 0;
}