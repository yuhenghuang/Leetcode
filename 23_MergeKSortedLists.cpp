#include <local_leetcode.hpp>

struct Comparator {
  bool operator()(const ListNode* x, const ListNode* y) const {
    return x->val > y->val;
  }
};

class Solution {
  private:
    ListNode* merge2(ListNode* l1, ListNode* l2) {
      if (!l1)
        return l2;
      else if (!l2)
        return l1;

      ListNode head(-1);
      ListNode* p = &head;
      while (l1 && l2) {
        if (l1->val < l2->val) {
          p->next = l1;
          l1 = l1->next;
        }
        else {
          p->next = l2;
          l2 = l2->next;
        }
        p = p->next;
      }

      p->next = l1 ? l1 : l2;

      return head.next;
    }

  public:
    ListNode* mergeKListsDQ(vector<ListNode*> lists) {
      int n = lists.size();
      if (n==0)
        return nullptr;

      while (n>1) {
        int i=0;

        while (i*2<n)
          lists[i++] = i*2==n-1 ? lists[i*2] : merge2(lists[i*2], lists[i*2+1]);

        n = i;
      }

      return lists[0];
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode dummy(-1);
      ListNode* p = &dummy;

      // priority_queue<ListNode*, deque<ListNode*>, Comparator> heap;

      priority_queue<
        ListNode*, 
        deque<ListNode*>, 
        function<bool(const ListNode*, const ListNode*)>
      > heap(
        [](const ListNode* x, const ListNode* y) -> bool {
          return x->val > y->val;
        }
      );

      for (auto ptr : lists)
        if (ptr)
          heap.push(ptr);

      while (!heap.empty()) {
        p->next = heap.top();
        heap.pop();
        p = p->next;
        if (p->next)
          heap.push(p->next);
      }

      return dummy.next;
    }
};


int main() {
  EXECS(Solution::mergeKLists);
  EXECS(Solution::mergeKListsDQ);
  return 0;
}