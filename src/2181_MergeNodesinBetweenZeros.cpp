#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* mergeNodes(ListNode* head) {
      head = head->next;

      ListNode* p = head;
      while (p) {
        ListNode* q = p->next;
        while (q->val != 0) {
          p->val += q->val;
          q = q->next;
        }

        p->next = q->next;
        p = p->next;
      }

      return head;
    }
};


int main() {
  EXECS(Solution::mergeNodes);
  return 0;
}