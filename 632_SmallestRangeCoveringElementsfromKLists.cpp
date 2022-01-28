#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      int r = INT_MIN;

      typedef vector<int>::iterator iter_t;
      typedef pair<iter_t, iter_t> pii_t;

      priority_queue<
        pii_t, 
        vector<pii_t>, 
        function<bool (const pii_t&, const pii_t&)>
      > heap(
        [](const pii_t& x, const pii_t& y) -> bool {
          return *x.first > *y.first;
        }
      );

      for(auto& ls : nums) {
        heap.emplace(ls.begin(), ls.end());
        r = max(r, ls.front());
      }

      int l = *(heap.top().first);

      pair<int, int> res(l, r);

      while (true) {
        pii_t p = heap.top();
        heap.pop();

        // one list runs out
        if (++p.first == p.second)
          break;
        else {
          heap.push(std::move(p));

          // update right and left bounds
          r = max(r, *p.first);
          l = *(heap.top().first);

          if (r - l < res.second - res.first)
            res = make_pair(l, r);
        }
      }
      
      return {res.first, res.second};
    }
};


int main() {
  EXECS(Solution::smallestRange);
  return 0;
}