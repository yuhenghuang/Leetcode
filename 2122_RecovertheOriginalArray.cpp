#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> recoverArray(vector<int>& nums) {
      int n = nums.size();

      sort(nums.begin(), nums.end());

      bool seen[n];

      int k;
      for (int p = 1; p < n; ++p)
        if (nums[p] != nums[p-1] && ((nums[0] + nums[p]) % 2 == 0)) {
          k = (nums[p] - nums[0]) / 2;

          int i = 0;
          int j = p;
          int count = 0;

          memset(seen, 0, sizeof(seen));

          while (j < n) {
            while (i < n && seen[i])
              ++i;

            seen[i] = true;

            int t = nums[i] + 2 * k;
            while (j < n && nums[j] < t)
              ++j;

            if (j < n) {
              seen[j] = true;

              if (nums[j] == t)
                count += 2;
            }

            ++i;
            ++j;
          }

          if (count == n)
            break;
        }

      int j = 0;

      vector<int> res;
      res.reserve(n/2);

      memset(seen, 0, sizeof(seen));

      for (int i = 0; i < n; ++i)
        if (!seen[i]) {
          res.push_back(nums[i] + k);
          
          int t = nums[i] + 2 * k;
          while (nums[j] < t)
            ++j;

          seen[j++] = true;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::recoverArray);
  return 0;
}