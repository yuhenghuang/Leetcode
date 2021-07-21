#include "utils3.hpp"

class Solution {
  private:
    vector<vector<int>> res;

    vector<vector<int>> twoSum(const vector<int>& nums, int i, int t) {
      vector<vector<int>> res;

      int l = 0, r = i;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum < t || (l > 0 && nums[l] == nums[l-1]))
          ++l;
        else if (sum > t || (r < i && nums[r] == nums[r+1]))
          --r;
        else
          res.push_back({nums[l++], nums[r--]});
      }

      return res;
    }
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      res.clear();

      map<int, int> m;
      for (int& num : nums) 
        ++m[num];

      vector<int> tri;
      dfs(0, tri, m, m.begin());
      return res;
    }

    void dfs(int target, vector<int>& triplet, map<int, int>& m, map<int, int>::iterator iter) {
        if (triplet.size()==2) {
          if (target>=triplet.back()) {
            iter = m.find(target);
            if (iter!=m.end() && iter->second>0) {
              triplet.push_back(iter->first);
              res.push_back(triplet);
              triplet.pop_back();
            }
          }
          return;
        }

      for(; iter!=m.end(); ++iter) {
        if (!iter->second) continue;
        triplet.push_back(iter->first);
        --iter->second;
        dfs(target-iter->first, triplet, m, iter);
        triplet.pop_back();
        ++iter->second;
      }
    }

    vector<vector<int>> threeSumOn2(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      vector<vector<int>> res;

      int i = nums.size() - 1;
      for (int j = i; j > 1; --j)
        if (j == i || nums[j] != nums[j+1]) 
          for (vector<int>& p : twoSum(nums, j - 1, -nums[j])) {
            res.emplace_back(std::move(p)).push_back(nums[j]);
          }

      return res;
    }
};

int main() {
  UFUNCS(Solution::threeSum);
  UFUNCS(Solution::threeSumOn2);
  return 0;
}