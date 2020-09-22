#include "utils.hpp"
#include <fstream>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode* dummy = new ListNode(0, head);
      
      stack<pair<int, ListNode*>> st;
      unordered_set<int> se;
      ListNode* p = dummy;
      int sum=0;
      while (p) {
        sum+= p->val;
        if (se.find(sum)!=se.end()) {
          while (st.top().first!=sum) {
            se.erase(st.top().first);
            st.pop();
          }
          st.top().second->next = p->next;
        }
        else {
          se.insert(sum);
          st.push({sum, p});
        }
        p = p->next;
      }

      return dummy->next;
    }
};


int main() {
  Solution sol;
  ListNode *head, *res;

  fstream f("Inputs/1171_RemoveZeroSumNodes.txt");
  string line;
  while (getline(f, line)) {
    head = utils::parse_linked_list(line);
    res = sol.removeZeroSumSublists(head);
    utils::print_linked_list(res);
  }
}