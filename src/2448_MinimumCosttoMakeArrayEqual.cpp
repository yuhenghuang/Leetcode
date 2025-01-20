#include <local_leetcode.hpp>

class Solution {
  public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
      typedef pair<int, int> ii_t;
      vector<ii_t> num_costs;

      transform(
        nums.begin(), nums.end(),
        cost.begin(),
        back_inserter(num_costs),
        [] (int n, int c) -> ii_t { return {n, c}; }
      );

      sort(
        num_costs.begin(), num_costs.end(),
        [] (const ii_t& p, const ii_t& q) { return p.first < q.first; }
      );

      int prev = num_costs.front().first;

      int64_t total_cost = 0;
      int64_t total_sum = 0;
      for (auto [n, c] : num_costs) {
        total_sum += c;
        total_cost += static_cast<int64_t>(n - prev) * c;
      }

      int64_t res = total_cost;

      int64_t prefix = 0;
      for (auto [n, c] : num_costs) {
        int64_t d = n - prev;

        total_cost += d * (2 * prefix - total_sum);

        if (total_cost < res)
          res = total_cost;

        prefix += c;
        prev = n;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minCost);
  return 0;
}