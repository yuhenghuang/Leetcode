#include "utils3.hpp"

class Solution {
  public:
    vector<int> nextLargerNodes(ListNode* head) {
      typedef pair<int, int> pii;
      priority_queue<pii, vector<pii>, greater<pii>> heap;

      vector<int> res;
      for (int i = 0; head != nullptr; head = head->next, ++i) {
        res.push_back(0);

        while (!heap.empty() && heap.top().first < head->val) {
          res[heap.top().second] = head->val;
          heap.pop();
        }

        heap.emplace(head->val, i);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::nextLargerNodes);
  return 0;
}