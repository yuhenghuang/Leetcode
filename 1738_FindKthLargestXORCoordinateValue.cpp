#include <local_leetcode.hpp>

class Solution {
  public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
      int m = matrix.size();
      int n = matrix[0].size();

      vector<vector<int>> prefix(m+1, vector<int>(n+1));

      priority_queue<int, vector<int>, greater<int>> heap;

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int val = prefix[i+1][j+1] = matrix[i][j] ^ prefix[i][j+1] ^ prefix[i+1][j] ^ prefix[i][j];

          if (heap.size() < k)
            heap.push(val);
          else if (heap.top() < val) {
            heap.pop();
            heap.push(val);
          }
        }

      return heap.top();
    }

    int kthLargestValueOn(vector<vector<int>>& matrix, int k) {
      // memory: O(n)

      int m = matrix.size();
      int n = matrix[0].size();

      vector<int> prev(n + 1);
      vector<int> curr(n + 1);

      priority_queue<int, vector<int>, greater<int>> heap;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int val = curr[j+1] = matrix[i][j] ^ prev[j+1] ^ curr[j] ^ prev[j];

          if (heap.size() < k)
            heap.push(val);
          else if (heap.top() < val) {
            heap.pop();
            heap.push(val);
          }
        }

        swap(curr, prev);
      }

      return heap.top();
    }
};


int main() {
  EXECS(Solution::kthLargestValue);
  EXECS(Solution::kthLargestValueOn);
  return 0;
}