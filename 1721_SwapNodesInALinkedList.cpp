#include "utils2.hpp"

class Solution {
  private:
    ListNode* findByIndex(ListNode* head, int i) {
      if (i==0)
        return head;
      else
        return findByIndex(head->next, i-1);
    }
  
  public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode dummy(0, head);
      
      int n = 0;
      ListNode* p = &dummy;
      while (p) {
        p = p->next;
        ++n;
      }
      
      // faster to use for or while loop to find node by index
      p = findByIndex(&dummy, k-1);
      ListNode* q = findByIndex(&dummy, n-k-1);

      // swap values
      // swap(p->next->val, q->next->val);
      
      if (p != q) {
        ListNode* tmp = p->next;
        
        p->next = q->next;
        q->next = tmp;
        
        tmp = p->next->next;
        
        p->next->next = q->next->next;
        q->next->next = tmp;
      }
      
      return dummy.next;
    }
};


int main() {
  UFUNC(Solution::swapNodes);
  return 0;
}