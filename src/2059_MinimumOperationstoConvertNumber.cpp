#include <local_leetcode.hpp>

class Solution {
  private:
    bool op(queue<int>& q, bool (&dp)[1001], int w, int t) {
      if (w == t)
        return true;

      if (0 <= w && w < 1001 && !dp[w]) {
        dp[w] = true;
        q.push(w);
      }
      
      return false;
    }

  public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
      bool dp[1001] = {0};
      dp[start] = true;

      queue<int> q;
      q.push(start);
      
      int res = 1;
      while (!q.empty()) {
        int n = q.size();
        while (n--) {
          int v = q.front();
          q.pop();

          for (int& num : nums) 
            if (op(q, dp, v + num, goal) || op(q, dp, v - num, goal) || op(q, dp, v ^ num, goal))
              return res;

        }
        ++res;
      }

      return -1;
    }
};


int main() {
  EXECS(Solution::minimumOperations);
  return 0;
}