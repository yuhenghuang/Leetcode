#include "utils3.hpp"

class Solution {
  public:
    ListNode* oddEvenListOld(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* even = head->next;
      ListNode* ptr_odd = head, * ptr_even = even, * ptr = even->next;
      unsigned int i = 1;
      while (ptr) {
        if (i % 2==1) {
          ptr_odd->next = ptr;
          ptr_odd = ptr_odd->next;
        }
        else {
          ptr_even->next = ptr;
          ptr_even = ptr_even->next;
        }
        ++i;
        ptr = ptr->next;
      }
      ptr_odd->next = even;
      ptr_even->next = nullptr;
      return head;
    }

    ListNode* oddEvenList(ListNode* head) {
      // until new algorithms come up
      return nullptr;
    }
};

int main() {
  UFUNCS(Solution::oddEvenListOld);
  UFUNCS(Solution::oddEvenList);
  return 0;
}