#include "utils2.hpp"

class Solution {
  public:
    int maxResult(vector<int>& nums, int k) {
      int n = nums.size();

      if (n == 1)
        return nums[0];

      priority_queue<pair<int, int>> heap;
      heap.emplace(nums[0], 0);

      for (int i = 1; i < n - 1; ++i) {
        while (heap.top().second < i - k)
          heap.pop();

        heap.emplace(heap.top().first + nums[i], i);
      }

      if (heap.top().second < n - 1 - k)
        heap.pop();

      return nums[n-1] + heap.top().first;
    }

    int maxResultOn(vector<int>& nums, int k) {
      int n = nums.size();

      // (index, sum)
      deque<pair<int, int>> q;
      q.emplace_back(0, nums.front());

      for (int i = 1; i < n; ++i) {
        int sum = nums[i] + q.front().second;

        while (!q.empty() && q.back().second <= sum)
          q.pop_back();

        while (!q.empty() && i - k >= q.front().first)
          q.pop_front();

        q.emplace_back(i, sum);
      }

      return q.back().second;
    }
};


int main() {
  {
    UFUNC(Solution::maxResult);
  }
  {
    UFUNC(Solution::maxResultOn);
  }
  return 0;
}