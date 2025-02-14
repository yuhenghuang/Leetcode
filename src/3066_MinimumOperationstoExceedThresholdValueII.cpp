#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(vector<int>& nums, int k) {
      constexpr int sup = 1e9;

      priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.end());

      int res = 0;

      for (;heap.size() > 1 and heap.top() < k;++res) {
        int x = heap.top() * 2; heap.pop();
        int y = heap.top(); heap.pop();

        heap.push(x < sup ? (x + y) : sup);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minOperations);
  return 0;
}