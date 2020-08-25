#include "DataStructure.h"
#include <stack>

using namespace std;

class Solution {
  public:
    void reorderList(ListNode* head) {
      stack<ListNode*> s;
      ListNode *p = head;
      while (p) {
        s.push(p);
        p = p->next;
      }


      int n=s.size() / 2;
      p = head;
      while (n--) {
        s.top()->next = p->next;
        p->next = s.top();
        p = s.top()->next;
        if (n==0) {
          if (n%2)
            s.top()->next = nullptr;
          else
            p->next = nullptr;
        }
        s.pop();
      }
    }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  for (int i=2; i<6; ++i) {
    p->next = new ListNode(i);
    p = p->next;
  }

  Solution sol;
  sol.reorderList(head);
  return 0;
}