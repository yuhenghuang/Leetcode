#include <local_leetcode.hpp>

class Solution {
  public:
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(), courses.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x[1] < y[1];
        }
      );

      // durations
      priority_queue<int, vector<int>> heap;
      
      // current time
      int t = 0;

      for (auto& p : courses) {
        // add new course
        if (t + p[0] <= p[1]) {
          t += p[0];
          heap.push(p[0]);
        }
        // replace old course
        else if (!heap.empty() && p[0] < heap.top()) {
          t += p[0] - heap.top();
          heap.pop();
          heap.push(p[0]);
        }
      }

      return heap.size();
    }
};


int main() {
  EXECS(Solution::scheduleCourse);
  return 0;
}