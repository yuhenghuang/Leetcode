#include "utils3.hpp"

class Solution {
  private:
    void dfs(int i, const vector<int>& nums, vector<int>& s, vector<vector<int>>& res) {
      res.push_back(s);

      for (int j = i; j < nums.size(); ++j)
        if (j == i || nums[j] != nums[j-1]) {
          s.push_back(nums[j]);

          dfs(j + 1, nums, s, res);
          
          s.pop_back();
        }
    }

  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      
      vector<int> s;
      vector<vector<int>> res;

      dfs(0, nums, s, res);

      return res;
    }
};


int main() {
  UFUNCS(Solution::subsetsWithDup);
  return 0;
}