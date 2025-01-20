#include <local_leetcode.hpp>

class Solution {
  private:
    ListNode* findMid(ListNode* head) {
      ListNode *p = nullptr;
      while (head && head->next) {
        p = p==nullptr ? head : p->next;
        head = head->next->next;
      }
      ListNode *q = p->next;
      p->next = nullptr;
      return q;
    }

    ListNode* merge(ListNode* p, ListNode* q) {
      ListNode dummy(INT_MIN);
      ListNode *tail = &dummy;
      while (p && q) {
        if (p->val < q->val) {
          tail->next = p;
          p = p->next;
        }
        else {
          tail->next = q;
          q = q->next;
        }
        tail = tail->next;
      }
      tail->next = p ? p : q;
      return dummy.next;
    }
  public:
    ListNode* sortList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode *mid = findMid(head);
      ListNode *p = sortList(head);
      ListNode *q = sortList(mid);
      return merge(p, q);
    }


    ListNode* sortListBubble(ListNode* head) {
      if (!head || !head->next) return head;

      ListNode dummy(INT_MIN, head);

      ListNode *p, *q = nullptr, *ed;

      bool swaped = true;
      while (swaped) {
        ed = q;
        p = &dummy;
        q = p->next;
        swaped = false;

        while (q->next != ed) {
          if (p->next->val > q->next->val) {
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            
            p = p->next;
            swaped = true;
          }
          else {
            p = p->next;
            q = p->next;
          }
        }
      }

      return dummy.next;
    }
};


int main() {
  /*
  Solution sol;

  ListNode *head, *res;

  ifstream f("Inputs/148_SortList.txt");
  string line;
  while (getline(f, line)) {
    head = utils::parse_linked_list(line);
    res = sol.sortList(head);

    utils::print_linked_list(res);
  }
  */

  EXECS(Solution::sortList);
  EXECS(Solution::sortListBubble);

  return 0;
}