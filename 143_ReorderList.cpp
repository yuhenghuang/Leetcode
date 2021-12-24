#include <local_leetcode.hpp>

class Solution {
  public:
    void reorderList(ListNode* head) {
      stack<ListNode*> s;
      ListNode *p = head;
      while (p) {
        s.push(p);
        p = p->next;
      }


      int n=s.size() / 2;
      p = head;
      while (n--) {
        s.top()->next = p->next;
        p->next = s.top();
        p = s.top()->next;
        if (n==0) {
          if (n%2)
            s.top()->next = nullptr;
          else
            p->next = nullptr;
        }
        s.pop();
      }
    }

    // O(1) space
    void reorderListO1(ListNode* head) {
      ListNode dummy(0, head);

      ListNode* p = &dummy;
      ListNode* q = &dummy;

      while (q->next) {
        p = p->next;
        q = q->next;
        if (q->next)
          q = q->next;
      }

      q = p->next;
      // set end of first half
      p->next = nullptr;

      p = q;
      if (p) {
        q = p->next;
        // set end of second half
        p->next = nullptr;
      }
      else
        q = nullptr;

      while (q) {
        ListNode* tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
      }

      q = dummy.next;
      ListNode* iter = &dummy;

      // second half (p) <= first half (q) in terms of length
      while (p) {
        iter->next = q;
        q = q->next;
        iter = iter->next;

        iter->next = p;
        p = p->next;
        iter = iter->next;
      }

      iter->next = q;
    }
};


int main() {
  EXECS(Solution::reorderList);
  EXECS(Solution::reorderListO1);
  return 0;
}