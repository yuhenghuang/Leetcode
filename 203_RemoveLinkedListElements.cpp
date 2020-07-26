#include "DataStructure.h"
#include <iostream>
using namespace std;

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* dummy = new ListNode(0, head);
      ListNode* p = dummy, * q;
      while (p) {
        q = p->next;
        if (q && q->val==val) {
          p->next = q->next;
          p = q->next;
          delete q;
        }
        else 
          p = q;
      }
      return dummy->next;
    }
};

int main() {
  Solution sol;
  int arr[7] = {1,2,6,3,4,5,6};
  ListNode* head = new ListNode(arr[0]);
  ListNode* p = head, *q;
  for (int i=1; i<7; ++i) {
    q = new ListNode(arr[i]);
    p->next = q;
    p = q;
  }

  ListNode* res = sol.removeElements(head, 6);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}