#include "utils3.hpp"

class Solution {
  private:
    void dfs(int i, int t, vector<int>& nums, vector<int>& s, vector<vector<int>>& res) {
      if (t == 0) {
        res.push_back(s);
        return;
      }

      for (int j = i; j < nums.size(); ++j) {
        // early stop
        if (nums[j] > t)
          break;

        if (j == i || nums[j] != nums[j-1]) {
          s.push_back(nums[j]);
          dfs(j + 1, t - nums[j], nums, s, res);
          s.pop_back();
        }
      }
    }

  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());

      vector<int> s;
      vector<vector<int>> res;

      dfs(0, target, candidates, s, res);
      return res;
    }
};


int main() {
  UFUNCS(Solution::combinationSum2);
  return 0;
}