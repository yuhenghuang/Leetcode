#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();

      priority_queue<int, vector<int>, greater<int>> heap;
      heap.push(0);

      vector<int> dp(n);
      dp[0] = -(1e9 + 7);

      int res = INT_MIN;

      int sum = 0;
      for (int i = 1; i < n; ++i) {
        sum += arr[i-1];

        dp[i] = sum - heap.top();

        // no deletion subarrays
        if (dp[i] > res)
          res = dp[i];

        heap.push(sum);
      }

      res = max(res, sum + arr[n - 1] - heap.top());

      while (!heap.empty())
        heap.pop();

      sum = 0;
      heap.push(0);

      for (int i = n - 2; i >= 0; --i) {
        sum += arr[i+1];

        int val = sum - heap.top();

        heap.push(sum);

        // delete index i
        res = max(res, val + dp[i]);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumSum);
  return 0;
}