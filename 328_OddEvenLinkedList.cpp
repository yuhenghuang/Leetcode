#include "DataStructure.h"
#include <iostream>
using namespace std;

class Solution {
  public:
    ListNode* oddEvenList(ListNode* head) {
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
};

int main() {
  ListNode* arr[5];
  for (int i=0; i<5; ++i)
    arr[i] = new ListNode(i+1);
  for (int i=1; i<5; ++i)
    arr[i-1]->next = arr[i];

  ListNode* head = arr[0];
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
  
  Solution sol;
  head = sol.oddEvenList(arr[0]);

  while (head) {
    cout << head->val << endl;
    head = head->next;
  }
  return 0;
}