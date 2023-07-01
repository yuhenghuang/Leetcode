#include <local_leetcode.hpp>

class Solution {
  public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      typedef pair<int, int> ii_t;

      const int n = costs.size();

      // (cost, index)
      priority_queue<ii_t, vector<ii_t>, greater<ii_t>> heap;

      int i = 0;
      for (; i < candidates; ++i)
        heap.emplace(costs[i], i);

      int j = n - 1;
      for (; j > i && j + candidates >= n; --j)
        heap.emplace(costs[j], j);

      int64_t res = 0;
      while (k--) {
        auto [cost, index] = heap.top();
        heap.pop();

        res += cost;

        // has remaining workers
        if (i <= j) {
          if (index < i) {
            heap.emplace(costs[i], i);
            ++i;
          }
          else {
            heap.emplace(costs[j], j);
            --j;
          }
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::totalCost);
  return 0;
}