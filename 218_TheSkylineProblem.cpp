#include "utils.hpp"

class Solution {
  private:
    void go_down(int x_max, priority_queue<pair<int, int>>& heap, vector<vector<int>>& res) {
      while (x_max > heap.top().second) {
        int x = heap.top().second;
        heap.pop();
        while (heap.top().second <= x)
          heap.pop();

        res.push_back({x, heap.top().first});
      }
    }
  public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      priority_queue<pair<int, int>> heap;
      heap.push({0, INT_MAX});
      vector<vector<int>> res;

      for (const vector<int>& b : buildings) {

        go_down(b[0], heap, res);

        if (b[2]>heap.top().first) {
          if (!res.empty() && res.back()[0]==b[0])
            res.back()[1] = max(res.back()[1], b[2]);
          else
            res.push_back({b[0], b[2]});
        }

        heap.push({b[2], b[1]});
      }

      go_down(INT_MAX, heap, res);

      // for corner case
      if (heap.top().first>0)
        res.push_back({heap.top().first, 0});

      return res;
    }
};


int main() {
  UFUNC(Solution::getSkyline);
  return 0;
}