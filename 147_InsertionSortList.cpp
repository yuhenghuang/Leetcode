#include "utils2.hpp"

class Solution {
  private:
    void insert(ListNode* head, ListNode* node) {
      while (head->next->val < node->val) {
        head = head->next;
      }

      node->next = head->next;
      head->next = node;
    }
  public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode dummy(INT_MIN, head);

      head = &dummy;

      while (head->next) {
        if (head->val > head->next->val) {
          ListNode *p = head->next;
          head->next = p->next;
          insert(&dummy, p);
        }
        else {
          head = head->next;
        }
      }
      
      return dummy.next;
    }
};


int main() {
  UFUNC(Solution::insertionSortList);
  return 0;
}