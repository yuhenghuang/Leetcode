#include "utils3.hpp"

class Solution {
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      int min_dist = INT_MAX;
      int max_dist = 0;

      int prev_idx = -1;
      int prev_val = head->val;

      for(int i = 0; head != nullptr; head = head->next, ++i) {
        if (head->next && 
            ((head->val > prev_val && head->val > head->next->val) ||
             (head->val < prev_val && head->val < head->next->val))) {
          
          if (prev_idx >= 0) {
            min_dist = min(min_dist, i - prev_idx);
            max_dist += i - prev_idx;
          }

          prev_idx = i;
        }

        prev_val = head->val;
      }

      // less than 2 critical points
      if (min_dist == INT_MAX)
        return {-1, -1};

      return {min_dist, max_dist};
    }
};


int main() {
  UFUNCS(Solution::nodesBetweenCriticalPoints);
  return 0;
}