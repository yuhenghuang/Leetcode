#include <local_leetcode.hpp>

class Solution {
  public:
    int minStoneSum(vector<int>& piles, int k) {
      int total = 0;
      priority_queue<int> heap;
      for (const int& p : piles) {
        total += p;
        heap.push(p);
      }

      for (int i = 0; i < k && !heap.empty() && heap.top() > 1; ++i) {
        int p = heap.top(); heap.pop();
        
        total -= p >> 1;
        heap.push((p >> 1) + (p & 1));
      }

      return total;
    }
};


int main() {
  EXECS(Solution::minStoneSum);
  return 0;
}