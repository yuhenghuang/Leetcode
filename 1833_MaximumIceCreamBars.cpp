#include <local_leetcode.hpp>

class Solution {
  public:
    int maxIceCream(vector<int>& costs, int coins) {
      // max heap
      priority_queue<int> heap;

      for (const int& cost : costs) {
        if (cost <= coins) {
          heap.push(cost);
          coins -= cost;
        }
        else if (!heap.empty() && heap.top() > cost) {
          coins += heap.top() - cost;
          heap.pop();
          heap.push(cost);
        }
      }

      return heap.size();
    }
};


int main() {
  EXECS(Solution::maxIceCream);
  return 0;
}