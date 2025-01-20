#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode dummy;

      ListNode* p = &dummy;
      int acc = 0;
      while (l1 || l2 || acc) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + acc;
        acc = sum / 10;
        p->next = new ListNode(sum%10);
        p = p->next;

        if (l1)
          l1 = l1->next;
        if (l2)
          l2 = l2->next;
      }

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::addTwoNumbers);
  return 0;
}