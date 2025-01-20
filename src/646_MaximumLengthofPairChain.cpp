#include <local_leetcode.hpp>

class Solution {
  public:
    int findLongestChain(vector<vector<int>>& _pairs) {
      typedef pair<int, int> ii_t;

      // far more efficient to sort pair<int, int> than vector<int>
      vector<ii_t> pairs;

      transform(
        _pairs.begin(), _pairs.end(),
        back_inserter(pairs),
        [] (const vector<int>& p) -> ii_t { return {p[0], p[1]}; }
      );

      sort(
        pairs.begin(), pairs.end(),
        [] (const ii_t& p, const ii_t& q) { return p.first < q.first; }
      );

      int res = 0;
      int right = INT_MIN;

      for (auto [l, r] : pairs) {
        if (right < l) {
          right = r;

          ++res;
        }
        else if (r < right)
          right = r;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findLongestChain);
  return 0;
}