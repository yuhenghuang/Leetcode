#include <numeric>
#include "utils3.hpp"

class Solution {
  public:
    int maxJumps(vector<int>& arr, const int d) {
      const int n = arr.size();
      
      vector<int> indices(n);
      iota(indices.begin(), indices.end(), 0);
      sort(indices.begin(), indices.end(),
        [&arr](int i, int j) -> bool {
          return arr[i] < arr[j];
        }
      );

      vector<int> dp(n, 1);

      int res = 0;
      for (const int i : indices) {
        int temp = 0;
        for (int j = i - 1; j >= max(0, i - d); --j)
          if (arr[i] > arr[j]) 
            temp = max(temp, dp[j]);
          else
            break;

        for (int j = i + 1; j <= min(n - 1, i + d); ++j)
          if (arr[i] > arr[j]) 
            temp = max(temp, dp[j]);
          else
            break;

        res = max(res, dp[i] += temp);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxJumps);
  return 0;
}