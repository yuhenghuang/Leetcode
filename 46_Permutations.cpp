#include "utils3.hpp"

class Solution {
  private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<bool>& seen, vector<int>& s) {
      if (s.size() == nums.size()) {
        res.push_back(s);
        return;
      }

      for (int i = 0; i < nums.size(); ++i)
        if (!seen[i]) {
          seen[i] = true;
          s.push_back(nums[i]);

          dfs(nums, res, seen, s);

          s.pop_back();
          seen[i] = false;
        }
    }

  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int> s;
      vector<bool> seen(nums.size());
      vector<vector<int>> res;

      dfs(nums, res, seen, s);

      return res;
    }
};


int main() {
  UFUNCS(Solution::permute);
  return 0;
}