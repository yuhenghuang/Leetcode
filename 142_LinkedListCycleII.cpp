#include <local_leetcode.hpp>

class Solution {
  private:
    ListNode* nextNode(ListNode* p) {
      return p ? p->next : nullptr;
    }
  public:
    ListNode* detectCycle(ListNode* head) {
      ListNode *p = head, *q = head;
      p = nextNode(p);
      q = nextNode(nextNode(q));
      while (p!=q) {
        p = nextNode(p);
        q = nextNode(nextNode(q));
      }

      p = head;
      while (p!=q) {
        p = nextNode(p);
        q = nextNode(q);
      }

      return p;
    }

    int detectCycle(ListNode* head, int pos) {
      return ll::find_index(
        head,
        detectCycle(ll::create_cycle(head, pos))
      );
    }
};


int main() {
  EXECS(Solution::detectCycle, int, (ListNode*, int));
}