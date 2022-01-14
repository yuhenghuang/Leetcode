#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
      int n = queries.size();

      vector<int> indicies(n);
      iota(indicies.begin(), indicies.end(), 0);

      sort(
        indicies.begin(),
        indicies.end(),
        [&queries](const int& i, const int& j) -> bool {
          return queries[i] < queries[j];
        }
      );

      sort(
        items.begin(),
        items.end(),
        [](auto& i, auto& j) -> bool {
          return i[0] < j[0];
        }
      );

      vector<int> res(n);

      auto iter = items.begin();
      // beauty
      int b = 0;
      for (const int& i : indicies) {
        for (; iter != items.end() && iter->front() <= queries[i]; ++iter)
          b = max(b, iter->back());

        res[i] = b;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumBeauty);
  return 0;
}