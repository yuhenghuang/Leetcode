#include "utils.hpp"

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, deque<int>, greater<int>> heap;
      for (int num : nums) {
        if (heap.size()<k)
          heap.push(num);
        else {
          heap.push(num);
          heap.pop();
        }
      }

      return heap.top();
    }
};


int main() {
  UFUNC(Solution::findKthLargest);
  return 0;
}