#include "utils.hpp"
#include <stack>

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *p = l1, *q = l2;
      stack<ListNode*> s1, s2;

      while (p) {
        s1.push(p);
        p = p->next;
      }

      while (q) {
        s2.push(q);
        q = q->next;
      }

      int rem = 0, v1, v2;
      while (!s1.empty() || !s2.empty() || rem>0) {
        if (s1.empty()) {
          v1 = 0;
        }
        else {
          v1 = s1.top()->val;
          s1.pop();
        }

        if (s2.empty()) {
          v2 = 0;
        }
        else {
          v2 = s2.top()->val;
          s2.pop();
        }

        int sum = v1 + v2 + rem;
        rem = sum / 10;

        p = new ListNode(sum%10, q);
        q = p;
      }

      return p;
    }
};


int main() {
  UFUNC(Solution::addTwoNumbers);
  return 0;
}