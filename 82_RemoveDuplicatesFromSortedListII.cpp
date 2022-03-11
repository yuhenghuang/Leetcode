#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode dummy;

      ListNode* p = &dummy;
      ListNode* q;
      while (head) {
        q = head->next;
        while (q && q->val==head->val)
          q = q->next;

        if (q == head->next) {
          p->next = head;
          p = p->next;
        }

        head = q;
      }
      p->next = nullptr;

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::deleteDuplicates);
  return 0;
}