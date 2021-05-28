#include "utils2.hpp"

class Solution {
  public:
    bool isPossible(vector<int>& target) {
      if (target.size() == 1)
        return target[0] == 1;

      // max heap
      priority_queue<int> heap;

      // total sum
      long sum = 0;
      for (int num : target) {
        sum += num;
        heap.push(num);
      }

      while (heap.top() > 1) {
        // max value
        int c = heap.top(); heap.pop();

        // diff btw max value and second-max value
        int d = c - heap.top();
        if (d == 0)
          return false;

        long a = sum - c;

        // reduce max value to be non-greater than second-max value
        int b = c - (d / a + (d % a != 0)) * a;
        if (b < 1)
          return false;

        // update total sum and array(heap)
        sum = a + b;
        heap.push(b);
      }

      return true;
    }
};


int main() {
  UFUNC(Solution::isPossible);
  return 0;
}