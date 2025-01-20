#include <local_leetcode.hpp>

class Solution {
  public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
      // O(n * n * d)

      int n = jobDifficulty.size();

      if (n < d)
        return -1;

      // 1-day case
      vector<int> prev(n + 1);

      for (int i = 0 ; i < n; ++i)
        prev[i+1] = max(prev[i], jobDifficulty[i]);


      vector<int> curr;

      for (int k = 1; k < d; ++k) {
        curr.assign(n+1, INT_MAX);

        for (int i = 0; i < n; ++i) {
          int difficulty = 0;
          for (int j = i; j >= k; --j) {
            difficulty = max(difficulty, jobDifficulty[j]);

            curr[i+1] = min(curr[i+1], prev[j] + difficulty);
          }
        }

        swap(prev, curr);
      }

      return prev.back();
    }
};


int main() {
  EXECS(Solution::minDifficulty);
  return 0;
}