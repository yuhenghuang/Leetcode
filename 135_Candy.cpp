#include <local_leetcode.hpp>

class Solution {
  public:
    int candy(vector<int>& ratings) {
      // size of ratings
      int n = ratings.size();

      // indices vector of ratings
      vector<int> indices(n);
      for (int i = 1; i < n; ++i)
        indices[i] = i;

      sort(indices.begin(), indices.end(),
        [&ratings](int i, int j) -> bool {
          return ratings[i] < ratings[j];
        }
      );

      vector<int> dp(n);
      for (int i : indices) {
        dp[i] = 1 + max((i > 0 && ratings[i-1] < ratings[i]) ? dp[i-1] : 0,
                        (i < n-1 && ratings[i+1] < ratings[i]) ? dp[i+1] : 0);
      }

      return reduce(dp.begin(), dp.end(), 0, std::plus<int>());
    }

    int candyOn(vector<int>& ratings) {
      int n = ratings.size();

      vector<int> dp(n, 1);

      for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i-1])
          dp[i] = dp[i-1] + 1;

      for (int i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i+1])
          dp[i] = max(dp[i], dp[i+1] + 1);

      return reduce(dp.begin(), dp.end());
    }
};


int main() {
  EXECS(Solution::candyOn);
  EXECS(Solution::candy);
  return 0;
}
