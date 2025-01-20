#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* middleNode(ListNode* head) {
      ListNode dummy(0, head);

      ListNode* p = &dummy;
      ListNode* q = &dummy;
      
      while (p) {
        p = p->next;
        if (p)
          p = p->next;

        q = q->next;
      }

      return q;
    }
};


int main() {
  EXECS(Solution::middleNode);
  return 0;
}