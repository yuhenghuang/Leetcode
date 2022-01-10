#include <local_leetcode.hpp>

class Solution {
  private:
    ListNode* recurse(ListNode* head, int n) {
      if (!head)
        return nullptr;

      ListNode* tail = head;
      int i = 1;
      for (; i < n && tail->next; ++i)
        tail = tail->next;

      if (i % 2) { // odd length
        tail->next = recurse(tail->next, n + 1);
        return head;
      }
      else { // even length
        ListNode* p = head;
        ListNode* q = head->next;
        while (p != tail) {
          ListNode* tmp = q->next;
          q->next = p;
          p = q;
          q = tmp;
        }

        head->next = recurse(q, n + 1);
        return tail;
      }
    }

  public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
      return recurse(head, 1);
    }
};


int main() {
  EXECS(Solution::reverseEvenLengthGroups);
  return 0;
}