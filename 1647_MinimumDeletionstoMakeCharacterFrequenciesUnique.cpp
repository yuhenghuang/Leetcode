#include <local_leetcode.hpp>

class Solution {
  public:
    int minDeletions(string s) {
      int count[27] = {0};
      count[26] = INT_MAX;
      for (char c : s)
        ++count[c - 'a'];

      sort(begin(count), end(count), greater<int>());

      int res = 0;
      for (int i = 1; i <= 26; ++i) {
        if (count[i] == 0)
          break;
        else if (count[i-1] > count[i])
          continue;
        else if (count[i-1] == 0){
          res += count[i] - count[i-1];
          count[i] = 0;
        }
        else {
          res += count[i] - count[i-1] + 1;
          count[i] = count[i-1] - 1;
        }

      }

      return res;
    }

    int minDeletionsHeap(string s) {
      int count[26] = {0};

      for (char c : s)
        ++count[c - 'a'];

      int res = 0;
      priority_queue<int> heap(begin(count), end(count)); // max heap;

      while (heap.size() > 1 && heap.top() > 0) {
        int f = heap.top();
        heap.pop();

        // characters of the same frequency found
        if (heap.top() == f) {
          heap.push(f - 1); // decrement frequency of either character by 1
          ++res; // increment result
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minDeletions);
  EXECS(Solution::minDeletionsHeap);
  return 0;
}