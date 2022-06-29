#include <local_leetcode.hpp>

class Solution {
  public:
    int furthestBuildingOld(vector<int>& heights, int bricks, int ladders) {
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

    int furthestBuildingWrong(vector<int>& heights, int bricks, int ladders) {
      // wrong answer, suboptimal

      int n = heights.size();

      // max heap
      priority_queue<int, vector<int>> heap;
      heap.push(-1);

      for (int i = 0 ; i + 1< n; ++i) {
        int h = heights[i+1] - heights[i];

        if (h > 0) {
          if (bricks >= h) {
            heap.push(h);
            bricks -= h;
          }
          else if (ladders > 0) {
            if (heap.top() > h) {
              bricks += heap.top() - h;
              heap.pop();
            }

            --ladders;
          }
          else
            return i;
        }
      }

      return n - 1;
    }
};


int main() {
  EXECS(Solution::furthestBuildingOld);
  EXECS(Solution::furthestBuildingWrong);
  return 0;
}