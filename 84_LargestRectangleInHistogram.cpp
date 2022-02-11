#include <local_leetcode.hpp>

class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();

      int i = 0;
      int res = 0;
      stack<int> s;
      while (i<n || !s.empty()) {
        if (i<n && (s.empty() || heights[s.top()] <= heights[i])) {
          s.push(i);
          ++i;
        }
        else {
          int j = s.top(); s.pop();
          int temp = heights[j] * (i - (s.empty() ? 0 : (s.top()+1)));
          res = max(temp, res);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::largestRectangleArea);
  return 0;
}