#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>

class Solution {
  private:
    vector<int> res;
  public:
    vector<int> numsSameConsecDiff(int N, int K) {
      res.clear();

      for (int i=1; i<10; ++i)
        dfs(i, N-1, K);

      if (N==1)
        res.push_back(0);
      return res;
    }

    void dfs(int cur, int N, int &K) {
      if (N==0) {
        res.push_back(cur);
        return;
      }

      int rem = cur % 10;
      cur *= 10;
      if (rem+K<10) dfs(cur+rem+K, N-1, K);
      if (K>0 && rem-K>=0) dfs(cur+rem-K, N-1, K);
    }

    vector<int> numsSameConsecDiffNew(int n, int k) {
      // O(2^n)

      vector<int> prev(9), curr;

      // prev = [1, 2, ..., 9]
      iota(prev.begin(), prev.end(), 1);

      for (int i = n - 1; i > 0; --i) {
        for (const int& num : prev) {
          int d = num % 10;

          if (d + k < 10)
            curr.push_back(num * 10 + d + k);

          // k > 0 to get rid of duplicates
          if (k > 0 && d - k >= 0)
            curr.push_back(num * 10 + d - k);
        }

        swap(prev, curr);
        curr.clear();
      }

      return prev;
    }
};


int main() {
  /*
  Solution sol;
  vector<int> res = sol.numsSameConsecDiff(1, 0);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  */

  EXECS(Solution::numsSameConsecDiff);
  EXECS(Solution::numsSameConsecDiffNew);
  return 0;
}
