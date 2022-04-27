#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
      if (k == 1)
        return reduce(jobs.begin(), jobs.end());

      const int n = jobs.size();

      if (k == n)
        return *max_element(jobs.begin(), jobs.end());

      const int N = 1 << n;
      vector<int> time(N);
      vector<int> curr(N);
      vector<int> next(N, INT_MAX);

      for (int i = 1; i < N; ++i) {
        int j = __builtin_ctz(i);
        curr[i] = time[i] = time[i ^ (1 << j)] + jobs[j];
      }

      for (int p = 1; p < k - 1; ++p) {
        for (int i = 1; i < N; ++i)
          if (curr[i] < INT_MAX)
            for (int j = 1; j < N; ++j)
              if ((i & j) == 0) 
                next[i | j] = min(next[i | j], max(curr[i], time[j]));

        // use swap to ensure no new memory allocated
        swap(curr, next);
        next.assign(N, INT_MAX);
      }

      int res = INT_MAX;
      for (int i = 1; i < N - 1; ++i)
        res = min(res, max(curr[i], time[(N - 1) ^ i]));

      return res;
    }
};


int main() {
  EXECS(Solution::minimumTimeRequired);
  return 0;
}