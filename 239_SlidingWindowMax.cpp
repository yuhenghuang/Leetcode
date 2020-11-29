#include "utils.hpp"
#include <deque>

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();

      deque<pair<int, int>> d(2*k);

      vector<int> res;
      res.reserve(n-k+1);
      for (int i=0; i<n; ++i) {
        while (!d.empty() && d.front().first<=i-k)
          d.pop_front();

        while (!d.empty() && d.back().second<=nums[i])
          d.pop_back();

        d.push_back({i, nums[i]});

        if (i>=k-1)
          res.push_back(d.front().second);
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::maxSlidingWindow);
  return 0;
}