#include "utils.hpp"
#include <algorithm>

class Solution {
  private:
    int n;
    void dfs(vector<int>& s, const vector<int>& nums, vector<bool>& visited, vector<vector<int>>& res) {
      if (s.size()==n) {
        res.push_back(s);
        return;
      }

      for (int i=0; i<n; ++i) {
        if (visited[i] || ((i>0 && !visited[i-1] && nums[i-1]==nums[i]))) continue;
        visited[i] = true;
        s.push_back(nums[i]);
        dfs(s, nums, visited, res);
        s.pop_back();
        visited[i] = false;
      }
    }
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      n = nums.size();
      vector<int> s;
      s.reserve(n);
      vector<bool> visited(n);
      vector<vector<int>> res;
      dfs(s, nums, visited, res);

      return res;
    }
};


int main() {
  UFUNC(Solution::permuteUnique);
  return 0;
}