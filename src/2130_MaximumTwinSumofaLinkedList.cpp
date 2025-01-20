#include <local_leetcode.hpp>

class Solution {
  public:
    int pairSum(ListNode* head) {
      int n = 0;
      ListNode* p = head;

      while (p) {
        p = p->next;
        ++n;
      }

      n /= 2;
      p = head;
      stack<int> s;
      for (int i = 0; i < n; ++i) {
        s.push(p->val);
        p = p->next;
      }

      
      int res = 0;
      for (int i = 0; i < n; ++i) {
        res = max(res, p->val + s.top());

        s.pop();
        p = p->next;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::pairSum);
  return 0;
}