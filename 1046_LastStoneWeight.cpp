#include <local_leetcode.hpp>

class Solution {
  public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> heap(stones.begin(), stones.end());

      while (heap.size() > 1) {
        int x = heap.top(); heap.pop();
        int y = heap.top(); heap.pop();

        if (x != y)
          heap.push(abs(x - y));
      }

      return heap.empty() ? 0 : heap.top();
    }
};


int main() {
  EXECS(Solution::lastStoneWeight);
  return 0;
}