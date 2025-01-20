#include <local_leetcode.hpp>

class Solution {
  public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
      // wrong

      int n = boxes.size();

      int res = 0; // at port at index -1 and n

      for (int i = 1; i < n; ++i)
        if (boxes[i][0] != boxes[i-1][0])
          ++res;

      int weight = 0;
      vector<int> dp(n+1);

      deque<int> q;

      for (int i = 0; i < n; ++i) {
        // check max boxes
        if (!q.empty() && i - q.front() > maxBoxes) {
          weight -= boxes[q.front()][1];
          q.pop_front();
        }

        weight += boxes[i][1];
        q.push_back(i);

        // check max weight
        while (weight > maxWeight) {
          weight -= boxes[q.front()][1];
          q.pop_front();
        }
        
        dp[i+1] = dp[q.empty() ? 0 : q.front()] + 2;
      }

      return res + dp.back();
    }
};


int main() {
  EXECS(Solution::boxDelivering);
  return 0;
}