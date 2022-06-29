#include <local_leetcode.hpp>

class Solution {
  public:
    bool isPossibleOld(vector<int>& target) {
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

    bool isPossible(vector<int>& target) {
      if (target.size() == 1)
        return target[0] == 1;


      // max heap
      priority_queue<int> heap(target.begin(), target.end());

      int64_t sum = reduce(target.begin(), target.end(), (int64_t) 0);

      while (heap.top() > 1) {
        int num = heap.top();
        heap.pop();

        
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isPossibleOld);
  EXECS(Solution::isPossible);
  return 0;
}