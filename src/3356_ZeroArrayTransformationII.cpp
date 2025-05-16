#include <local_leetcode.hpp>

class Solution {
  public:
      int minZeroArray(vector<int>& nums, vector<vector<int>>& _queries) {
        const int n = _queries.size();

        typedef tuple<int, int, int> i3_t;

        vector<i3_t> queries(n);
        transform(
          _queries.begin(), _queries.end(),
          queries.begin(),
          [] (vector<int>& q) -> i3_t { return {q[0], q[1], q[2]}; }
        );

        int l = 0, r = n;
        while (l < r) {
          int m = l + (r - l) / 2;

          vector<i3_t> qs(queries.begin(), queries.begin() + m);
          sort(
            qs.begin(), qs.end(),
            [] (const i3_t& p, const i3_t& q) {
              return get<0>(p) < get<0>(q) or (get<0>(p) == get<0>(q) and get<1>(p) > get<1>(q));
            }
          );

          // ...
        }


        return l < n ? l : -1;
      }
  };


int main() {
  EXECS(Solution::minZeroArray);
  return 0;
}