#include "utils2.hpp"

class Solution {
  public:
    bool isPossible(vector<int>& target) {
      if (target.size() == 1)
        return target[0] == 1;

      priority_queue<int> heap;
      long sum = 0;
      for (int num : target) {
        sum += num;
        heap.push(num);
      }

      while (heap.top() > 1) {
        int c = heap.top(); heap.pop();
        int d = c - heap.top();
        if (d == 0)
          return false;

        long a = sum - c;
        int b = c - (d / a + (d % a != 0)) * a;
        if (b < 1)
          return false;

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