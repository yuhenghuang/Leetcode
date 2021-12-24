#include <local_leetcode.hpp>

class Solution {
  private:
    long maxDiff(int n, vector<int>& cuts) {
      sort(cuts.begin(), cuts.end());

      int res = max(cuts.front(), n - cuts.back());
      for (int i = 1; i < cuts.size(); ++i)
        res = max(res, cuts[i] - cuts[i-1]);

      return res;
    }

  public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      return (maxDiff(h, horizontalCuts) * maxDiff(w, verticalCuts)) % long(1e9 + 7);
    }
};


int main() {
  EXECS(Solution::maxArea);
  return 0;
}