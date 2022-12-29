#include <local_leetcode.hpp>

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
      if (!head)
        return nullptr;

      ListNode* odd = head; // end of odd nodes
      ListNode* even = head->next; // end of even nodes

      while (even && even->next) {
        // move next node of $even$ to the next of $odd$

        ListNode* tmp = even->next;

        even->next = tmp->next;

        tmp->next = odd->next;
        odd->next = tmp;

        odd = odd->next;
        even = even->next;
      }

      return head;
    }
};

int main() {
  EXECS(Solution::oddEvenListOld);
  EXECS(Solution::oddEvenList);
  return 0;
}
