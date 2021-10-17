#include <algorithm>
#include "utils3.hpp"

class Solution {
  private:
    vector<vector<int>> recurse(vector<int>& itvs, int k, int t) {
      int n = itvs.size();
      vector<vector<int>> res;

      if (t == 0) 
        res.assign(n, vector<int> {0});
      else {
        res.resize(n);
        --t;

        // each row: sum, indices
        vector<vector<int>> prefix = recurse(itvs, k, t);

        int offset = k * t;

        for (int i = 0; i + offset < n; ++i) {
          if (i == 0 || itvs[i + offset] + prefix[i][0] > res[i - 1][0]) {
            vector<int>& vec = res[i] = prefix[i];
            vec.push_back(i + offset);
            vec.front() += itvs[i + offset];
          }
          else
            res[i] = res[i - 1];
        }
      }

      return res;
    }


  public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
      int n = nums.size();

      vector<int> itvs(n - k + 1);

      int sum = 0;
      int i = n - 1;
      for (; i >= n - k; --i)
        sum += nums[i];

      itvs[i + 1] = sum;
      for (; i >= 0; --i)
        itvs[i] = itvs[i + 1] + nums[i] - nums[i + k];

      vector<int> res = recurse(itvs, k, 3)[n - 3 * k];
      return {res.begin() + 1, res.end()};
    }
};


int main() {
  UFUNCS(Solution::maxSumOfThreeSubarrays);
  return 0;
}