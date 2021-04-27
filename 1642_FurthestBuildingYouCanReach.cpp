#include "utils2.hpp"

class Solution {
  public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
      int n = heights.size();

      priority_queue<int, vector<int>, greater<int>> heap;

      for (int i = 0; i < n-1; ++i) {
        int h = heights[i+1] - heights[i];
        if (h <= 0) continue;

        if (heap.size() < ladders)
          heap.push(h);
        else if (ladders > 0 && heap.top() < h) {
          bricks -= heap.top();
          heap.pop();
          heap.push(h);
        }
        else 
          bricks -= h;

        if (bricks < 0)
          return i;
      }

      return n-1;
    }
};


int main() {
  UFUNC(Solution::furthestBuilding);
  return 0;
}