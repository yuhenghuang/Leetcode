#include "utils2.hpp"

class Solution {
  public:
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(), courses.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x[1] < y[1];
        }
      );

      priority_queue<int, vector<int>> heap;
      
      int t = 0;
      for (auto& p : courses) {
        if (t + p[0] <= p[1]) {
          t += p[0];
          heap.push(p[0]);
        }
        else if (!heap.empty() && p[0] < heap.top()){
          t += p[0] - heap.top();
          heap.pop();
          heap.push(p[0]);
        }
      }

      return heap.size();
    }
};


int main() {
  UFUNC(Solution::scheduleCourse);
  return 0;
}