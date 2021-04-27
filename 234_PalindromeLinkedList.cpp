#include "utils2.hpp"

class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      if (!head) return true;
      
      int n = 0;
      ListNode* p = head;
      while (p) {
        ++n;
        p = p->next;
      }
      
      int mid = (n-1) / 2;
      p = head;
      for (int i=0; i<mid; ++i)
        p = p->next;
      
      ListNode* q = p->next;
      p->next = nullptr;
      if (n % 2 == 0 && q) {
        p = q;
        q = q->next;
        p->next = nullptr;
      }
      
      while (p && q) {
        ListNode* s = q->next;
        q->next = p;
        p = q;
        q = s;
      }
      
      q = head;
      while (p != q) {
        if (p->val != q->val)
          return false;
        
        p = p->next;
        q = q->next;
      }
      
      return true;
    }
};


int main() {
  UFUNC(Solution::isPalindrome);
  return 0;
}