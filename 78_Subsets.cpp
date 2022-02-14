#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      // vector<int> temp;
      vector<vector<int>> res;

      // preallocate memory to avoid unnecessary copy
      res.reserve(1 << nums.size());

      res.push_back({});
      for (int i=0; i<nums.size(); ++i) {
        int N = res.size();
        for (int j=0; j<N; ++j) {
          /*
          temp = res[j];
          temp.push_back(nums[i]);
          res.push_back(std::move(temp));
          */
          res.emplace_back(res[j]).push_back(nums[i]);
        }
      }
      return res;
    }
};


int main() {
  EXECS(Solution::subsets);
  return 0;
}
