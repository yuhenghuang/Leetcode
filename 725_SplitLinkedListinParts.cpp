#include "utils3.hpp"

class Solution {
  public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      vector<ListNode*> res(k);

      int n = 0;
      ListNode* p = head;
      while (p) {
        ++n;
        p = p->next;
      }

      int i = 0;
      while (n > 0) {
        ListNode* p = head;
        res[i++] = p;

        int l = n / k + (n % k ? 1 : 0);

        n -= l;
        --k;

        while (--l)
          p = p->next;

        head = p->next;
        p->next = nullptr;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::splitListToParts);
  return 0;
}