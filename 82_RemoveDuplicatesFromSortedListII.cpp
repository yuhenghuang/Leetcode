#include "utils.hpp"

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy = new ListNode();

      ListNode* p = dummy;
      ListNode* q, * o;
      while (head) {
        q = head->next;
        while (q && q->val==head->val) {
          q = q->next;
        }

        if (q==head->next) {
          p->next = head;
          p = p->next;
          head = q;
        }

        while (head!=q) {
          o = head;
          head = head->next;
          delete o;
        }
      }
      p->next = nullptr;

      return dummy->next;
    }
};


int main() {
  UFUNC(Solution::deleteDuplicates);
  return 0;
}