#include "utils.hpp"

class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      if (!head) 
        return nullptr;
      else if (!head->next)
        return head;

      ListNode* q = head->next;

      head->next = swapPairs(q->next);
      q->next = head;
      return q;
    }
};


int main() {
  UFUNC(Solution::swapPairs);
  return 0;
}