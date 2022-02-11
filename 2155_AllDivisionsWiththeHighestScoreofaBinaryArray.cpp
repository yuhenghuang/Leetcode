#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> maxScoreIndices(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      for (int i = 0; i < n; ++i)
        sum += nums[i];

      int score = sum; // highest score

      vector<int> res {0};

      int prefix = 0;
      int curr; // current score
      for (int i = 0; i < n; ++i) {
        prefix += nums[i];
        // left + right
        curr = i + 1 - prefix + sum - prefix;

        if (curr >= score) {
          if (curr > score) {
            res.clear();
            score = curr;
          }
          res.push_back(i + 1);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxScoreIndices);
  return 0;
}