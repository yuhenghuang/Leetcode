#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int> res;

      int evensum = accumulate(nums.begin(), nums.end(), 0, [](const int& x, const int& y) { return x + ((y % 2) ? 0 : y); });

      for (auto& q : queries) {
        int old_value = nums[q[1]];
        int new_value = nums[q[1]] += q[0];

        // odd number
        if (old_value % 2) {
          // becomes even
          if (new_value % 2 == 0)
            evensum += new_value;
        }
        // even number
        else {
          // becomes odd
          if (new_value % 2)
            evensum -= old_value;
          else
            evensum += q[0];
        }

        res.push_back(evensum);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::sumEvenAfterQueries);
  return 0;
}
